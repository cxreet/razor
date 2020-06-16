#!/usr/bin/python
import sys, binascii, subprocess
from capstone import *
from elftools.elf.elffile import ELFFile
import operator
from bisect import bisect_left
import pefile
import re

sys.dont_write_bytecode = True

"""
python stitcher.py trace-*-*.txt exe out_exe.s callbacks.txt
"""

DEBUG = False

# platform info
is_linux = None
is_windows = None

# Windows
pe = None
elf = None

# binay entry point info
entry_point = 0
real_module_base = 0
expect_module_base = 0

# trace info
exe_bbs = []
cond_brs = {}
ind_calls = {}
all_bb_heads = []

# callback info
callbacks = {}

# label for symbolization
RIP_L_IDX = 0

def usage():
    print 'python stitcher.py trace-*-*.txt exe out_exe.s callbacks.txt'
    sys.exit(1)

def get_platform(binname):
    global is_linux, is_windows

    cmd = ["file", binname]
    output = subprocess.check_output(cmd)
    if "PE32+" in output or "PE32" in output:
        is_linux = False
        is_windows = True
    elif "ELF" in output:
        is_linux = True
        is_windows = False

"""
Whether the instruction at `addr` is executed.
"""
def find_instr(addr):
    if addr == all_bb_heads[0]:
        return True
    
    high = len(all_bb_heads)
    pos = bisect_left(all_bb_heads, addr, 1, high)

    if pos != high and all_bb_heads[pos] == addr:
        return True

    return False

"""
read callback functions
"""
def read_callbacks(callback_file_name):
    global callbacks

    with open(callback_file_name, 'r') as f:
        # e.g., L_0x400f30 9
        #       BB_start,  instr no.
        for line in f.readlines():
            tokens = line.strip().split()
            addr = int(tokens[0].split('L_')[-1], 16)
            idx = int(tokens[1])

            if addr not in callbacks:
                callbacks[addr] = [idx]
            else:
                callbacks[addr].append(idx)

"""
Read the trace log to get the executed block, taken/not-taken info
for conditional branches, targets of indirect calls.
"""
def read_trace(trace_log_file_name, orig_bin_file_name):
    global exe_bbs, cond_brs, ind_calls
    global entry_point, real_module_base, expect_module_base
    global is_linux, is_windows, pe, elf

    get_platform(orig_bin_file_name)

    # find expected load address and entry point
    if is_windows == True:
        pe = pefile.PE(orig_bin_file_name)
        expect_module_base = pe.OPTIONAL_HEADER.ImageBase
        entry_point = pe.OPTIONAL_HEADER.AddressOfEntryPoint + expect_module_base
    else:
        f = open(orig_bin_file_name, 'rb')
        elf = ELFFile(f)
        for seg in elf.iter_segments():
            if seg['p_type'] != 'PT_LOAD':
                continue
            else:
                expect_module_base = seg['p_vaddr']
                break
        entry_point = elf['e_entry']
        f.close()

    print "expect_module_base:\t", hex(expect_module_base)
    print "entry point:\t", hex(entry_point)

    with open(trace_log_file_name, 'r') as f:

        for line in f.readlines():
            line = line.strip()
            tokens = line.split()
            
            # read the MODULE_START
            if line.startswith('MODULE_START:'):
                real_module_base = int(tokens[-1], 16)
                print "real_module_base:\t", hex(real_module_base)
                real2expect = -real_module_base + expect_module_base

            
            # executed bbs
            # e.g., +B+ 0x400c88 0x400c97
            #       BB  start -- end
            if line.startswith('+B+'):
                bb_start = int(tokens[1], 16) + real2expect
                bb_end   = int(tokens[2], 16) + real2expect
                assert (bb_start > 0 and bb_end > 0 and bb_end >= bb_start)
                exe_bbs.append((bb_start,bb_end))
                continue

            # conditional branch
            # e.g., +CND+ 0x404000 3 
            #             addr     TNT: 3 means both T & NT
            if line.startswith('+CND+'):
                addr = int(tokens[1], 16) + real2expect
                taken = int(tokens[2], 16)
                cond_brs[addr] = taken
                continue

            # indirect call
            # e.g., +IND+ 0x400e00 0x7fe7c97bc770#2 0x400e06#1
            #             addr     target1#freq     target2#freq
            if line.startswith('+IND+'):
                temp_ind_calls = {}
                src_addr = int(tokens[1], 16) + real2expect

                for tgt in tokens[2:]:
                    subtokens = tgt.split('#')
                    dst_addr = int(subtokens[0], 16) + real2expect
                    freq = 0
                    if len(subtokens) == 2:
                        freq = int(subtokens[1])

                    if dst_addr not in temp_ind_calls:
                        temp_ind_calls[dst_addr] = freq
                    else:
                        print hex(src_addr), hex(dst_addr)
                        assert(False)

                # create ind_calls from temp_ind_calls sorted by frequence
                if src_addr not in ind_calls:
                    ind_calls[src_addr] = []
                tgts = sorted(temp_ind_calls.items(), key=operator.itemgetter(1), reverse=True)
                for k in tgts:
                    ind_calls[src_addr].append(k[0])
    
    # sort executed bbs
    exe_bbs.sort(key=operator.itemgetter(0))

    # save bb heads
    for bb in exe_bbs:
        all_bb_heads.append(bb[0])

def is_hex_str(s):
    s = s.strip()
    n = -1
    try:
        n = int(s, 16)
    except:
        n = -1
    
    if n == -1:
        return False

    return True

def generate_div_0(n, out_f):
    out_f.write('\t\tmov edx, 0\n')
    out_f.write('\t\tmov eax, %d\n' % n)
    out_f.write('\t\tmov ecx, 0\n')
    out_f.write('\t\tdiv ecx\n')

"""
For all untrigerred conditional branches, create dummy code as the target.
"""
def generate_cond_dummy(out_f):
    # L_cond_dummy
    out_f.write('\nL_cond_dummy:\n')
    generate_div_0(42, out_f)

"""
For all untrigerred indirect call target, create dummy code as the target.
"""
def generate_indcall_dummy(out_f):
    # L_indcall_dummy
    out_f.write('\nL_indcall_dummy:\n')
    generate_div_0(43, out_f)

"""
For unreachable code, create dummy code.
"""
def generate_unreachable_dummy(out_f):
    # L_unreachable_dummy
    out_f.write('\nL_unreachable_dummy:\n')
    generate_div_0(44, out_f)

"""
For each indirect call, create instrumentation function with label `L_indcall_address`.
"""
def instrument_ind_call(out_f, opcode, addr, real_tgt, next_addr, next_bb_addr):
    """
        L_indcall_target_0x#1:
        cmp  real_tgt, tgt1
        jne  L_indcall_target_0x#2
        call L_tgt1
        L_indcall_target_0x#2:
        cmp  real_tgt, tgt2
        jne  L_indcall_target_0x#3
        call L_tgt2
        ...
        L_indcall_target_0x#n:
        cmp  real_tgt, tgtn
        jne  L_indcall_dummy
        call L_tgtn
    """
    global RIP_L_IDX
    global ind_calls

    # refine targets, use the first target outside the main executable to replace
    # all outside targets.
    has_outside_tgt = False
    targets = ind_calls[addr]
    
    # rebuild the targets
    new_tgts = []
    outside_tgt = 0
    for tgt in targets:
        if not find_instr(tgt):
            #new_tgts.append(tgt)
            outside_tgt = tgt
            has_outside_tgt = True
        else:
            new_tgts.append(tgt)
    
    targets = new_tgts

    if has_outside_tgt:
        targets.append(outside_tgt)
    
    # iterate over each target
    for i in range(0, len(targets)):
        tgt = targets[i]

        # emit the label
        out_f.write('L_indcall_0x%x_target_0x%x:\n' % (addr, tgt))

        # emit the cmp instruction
        if find_instr(tgt):
            # tgt is in executed code, if tgt is not in executed code (e.g., library call),
            # directly jump to it without comparing.
            if 'ptr [rip +' in real_tgt:
                new_real_tgt = real_tgt.replace('rip', 'rip + ' + 'RIP_L_' + str(RIP_L_IDX))
                tmp_tokens = real_tgt.split("]")[0].split()
                offset_str = tmp_tokens[-1]
                sign = tmp_tokens[-2]
                if offset_str == "[rip":
                    offset_str = "0x0"
                    sign = "+"

                offset = int(offset_str, 16)
                if sign == "-":
                    abs_addr = next_addr - offset
                    new_real_tgt = new_real_tgt.replace("- " + offset_str+']', '+ 0x%x]' % (abs_addr))
                else:
                    abs_addr = next_addr + offset
                    new_real_tgt = new_real_tgt.replace("+ " + offset_str+']', '+ 0x%x]' % (abs_addr))

                out_f.write('\t\tcmp %s, 0x%x\n' % (new_real_tgt, tgt))
                out_f.write('L_' + str(RIP_L_IDX) + ':\n')
                RIP_L_IDX += 1
            else:
                out_f.write('\t\tcmp %s, 0x%x\n' % (real_tgt, tgt))
        
        # emit the jne and jmp instructions
        if i < len(targets) - 1:
            # if not equal, go to check next target
            out_f.write('\t\tjne L_indcall_0x%x_target_0x%x\n' % (addr, targets[i+1]))
            assert(find_instr(tgt))
            # if equal, do jmp/call
            out_f.write('\t\t%s L_0x%x\n' % (opcode, tgt))
            # after 'call', jmp over following comparions
            if not (opcode == "jmp"): # jmp will never come back
                out_f.write('\t\tjmp L_0x%x\n' % (next_addr))
        else:
            # for the last target
            if not has_outside_tgt:
                # if not equal, go to fail
                out_f.write('\t\tjne L_indcall_dummy\n')
                assert(find_instr(tgt))
                if not (next_bb_addr != None and opcode == "jmp" and tgt == next_bb_addr): # optimization
                    out_f.write('\t\t%s L_0x%x\n' % (opcode, tgt))
            else:
                # outside tgt
                if 'ptr [rip +' in real_tgt:
                    new_real_tgt = real_tgt.replace('rip', 'rip + ' + 'RIP_L_' + str(RIP_L_IDX))
                    tmp_tokens = real_tgt.split("]")[0].split()
                    offset_str = tmp_tokens[-1]
                    sign = tmp_tokens[-2]

                    if offset_str == "[rip":
                        offset_str = "0x0"
                        sign = "+"

                    offset = int(offset_str, 16)
                    if sign == "-":
                        abs_addr = next_addr - offset
                        new_real_tgt = new_real_tgt.replace("- " + offset_str+']', '+ 0x%x]' % (abs_addr))
                    else:
                        abs_addr = next_addr + offset
                        new_real_tgt = new_real_tgt.replace("+ " + offset_str+']', '+ 0x%x]' % (abs_addr))
                    out_f.write('\t\t%s %s\n' % (opcode, new_real_tgt))
                    out_f.write('L_' + str(RIP_L_IDX) + ':\n')
                    RIP_L_IDX += 1
                else:
                    out_f.write('\t\t%s %s\n' % (opcode, real_tgt))

    return

def fix_instruction_format(opcode, opstr):
    new_opstr = opstr

    if opcode == "fnstenv" or opcode == "fldenv":
        new_opstr = new_opstr.replace("dword ptr", "")

    if opcode.startswith("loop") or opcode == "xbegin":
        new_opstr = "L_" + new_opstr

    if opcode == "comisd":
        new_opstr = new_opstr.replace("xmmword", "qword")

    if opcode == "comiss":
        new_opstr = new_opstr.replace("xmmword", "dword")

    if opcode == "punpckldq":
        new_opstr = new_opstr.replace("qword", "dword")

    return new_opstr

"""
For all executed bbs, disassemble them to assembly code and
stitch them together based on the control flow info.
"""
def stitch(orig_bin_file_name, output_assembly_file_name, callback_file_name):
    print 'begin stitching...\n'
    global pe, elf
    global RIP_L_IDX
    global entry_point, expect_module_base

    read_callbacks(callback_file_name)
    
    with open(output_assembly_file_name, 'w') as out_f:
        # dump the entry point that is used by merge_bin.py
        out_f.write('// 0x%x\n' % entry_point)
        # the meta info for compiler
        out_f.write('.intel_syntax noprefix\n')

        with open(orig_bin_file_name, 'rb') as f:
            temp_bbs = exe_bbs[1:]
            temp_bbs.append(None)
            exe_bb_pairs = [(exe_bbs[i], temp_bbs[i]) for i in xrange(0, len(temp_bbs))]

            for bb_pair in exe_bb_pairs:
                bb = bb_pair[0]
                bb_next = bb_pair[1]
                assert(bb[0] > 0 and bb[1] > 0 and bb[1] >= bb[0])
                
                callback_idxs = []
                if bb[0] in callbacks: callback_idxs = callbacks[bb[0]]

                file_off = bb[0] - expect_module_base
                file_off = pe.get_offset_from_rva(file_off) if is_windows else file_off

                f.seek(file_off)
                raw_bytes = f.read(bb[1] - bb[0] + 1)
                md = Cs(CS_ARCH_X86, CS_MODE_64)

                if DEBUG: print hex(bb[0]), hex(bb[1])
                
                instr_idx = 0 # starts from 1
                out_f.write('\n')
                for instr in md.disasm(raw_bytes, bb[0]):
                    instr_idx += 1
                    opcode = instr.mnemonic
                    next_addr = instr.address + instr.size
                    
                    if DEBUG: out_f.write('addr:%x\n' % instr.address)
                    
                    out_f.write('L_0x%x:\n' % instr.address)
                    if opcode.startswith('j') or opcode.startswith('call'):
                        if is_hex_str(instr.op_str): # j*/call, target is a constant
                            # target is within executed code, symbolize it
                            if opcode.startswith('j'): # jump
                                if instr.address in cond_brs: # conditional jump
                                    # insert a following direct jump to the next block
                                    taken = cond_brs[instr.address]
                                    if taken == 1:
                                        # Taken
                                        out_f.write("\t\t{}\t{}\n".format(opcode, 'L_{}'.format(instr.op_str)))
                                        out_f.write('\t\tcall L_cond_dummy\n')
                                    elif taken == 2:
                                        # Non-taken
                                        out_f.write('\t\t%s L_cond_dummy\n' % (opcode))
                                    else:
                                        assert(taken == 3)
                                        out_f.write("\t\t{}\t{}\n".format(opcode, 'L_{}'.format(instr.op_str)))
                                else: # unconditional jump
                                    # HH: let's skip this jump if it goes to the following instruction
                                    if (bb_next == None) or (int(instr.op_str, 16) != bb_next[0]):
                                        out_f.write("\t\t{}\t{}\n".format(opcode, 'L_{}'.format(instr.op_str)))
                            else: # direct call
                                out_f.write("\t\t{}\t{}\n".format(opcode, 'L_{}'.format(instr.op_str)))

                        else: # indirect jump/call
                            print hex(instr.address)
                            assert((instr.address) in ind_calls)
                            instrument_ind_call(out_f, opcode, instr.address, instr.op_str, next_addr, bb_next[0])

                    else: # instructions that are not jump/call
                        if 'ptr [rip +' in instr.op_str or ("lea" in opcode and "rip" in instr.op_str):
                            new_opstr = instr.op_str.replace('rip', 'rip + ' + 'RIP_L_' + str(RIP_L_IDX))
                            new_opstr = new_opstr.replace('xword ptr', 'tbyte ptr')
                            tmp_tokens = instr.op_str.split("]")[0].split()
                            offset_str = tmp_tokens[-1]
                            sign = tmp_tokens[-2]

                            if offset_str == "[rip":
                                offset_str = "0x0"
                                sigh = "+"
                            offset = int(offset_str, 16)

                            if sign == "-":
                                abs_addr = next_addr - offset
                                new_opstr = new_opstr.replace("- " + offset_str+']', '+ 0x%x]' % (abs_addr))
                            else:
                                abs_addr = next_addr + offset
                                new_opstr = new_opstr.replace("+ " + offset_str+']', '+ 0x%x]' % (abs_addr))

                            # fix some spefical instructions' formats
                            new_opstr = fix_instruction_format(opcode, new_opstr)

                            if opcode.startswith("lea") and abs_addr in all_bb_heads:
                                # The new address should be the label address of the executed instruction, i.e. [L_0x413220]
                                new_opstr = re.sub("\[[^]]*\]", lambda x:"[L_{}]".format(hex(abs_addr)[:-1]), new_opstr)

                            out_f.write("\t\t{}\t{}\n".format(instr.mnemonic, new_opstr))
                            out_f.write('L_' + str(RIP_L_IDX) + ':\n')
                            RIP_L_IDX += 1
                            
                        else:
                            new_op_str = instr.op_str
                            new_op_str = new_op_str.replace('xword ptr', 'tbyte ptr')
                            new_mnemonic = instr.mnemonic
                            new_mnemonic = new_mnemonic.replace('rep movsd', 'rep movs')
                            
                            # fix callback
                            if instr_idx in callback_idxs and opcode.startswith('mov'):
                                tokens = new_op_str.split()
                                tokens[-1] = 'offset L_'+ tokens[-1]
                                new_op_str = ' '.join(tokens)
                            
                            out_f.write("\t\t{}\t{}\n".format(new_mnemonic, new_op_str))
                            
        # create the dummy code for untrigerred conditional branches and
        # instrumentation for each indirect call
        generate_cond_dummy(out_f)
        generate_indcall_dummy(out_f)
        generate_unreachable_dummy(out_f)

    return

"""
simply dump all executed instructions into the output_assembly_file
"""
def dump(orig_bin_file_name, output_assembly_file_name):
    global real_module_base, expect_module_base
    global is_linux, is_windows
    
    with open(output_assembly_file_name, 'w') as out_f:
        with open(orig_bin_file_name, 'rb') as f:
            for bb in exe_bbs:

                assert(bb[0] > 0 and bb[1] > 0 and bb[1] >= bb[0])
                
                file_off = bb[0] - expect_module_base
                file_off = pe.get_offset_from_rva(file_off) if is_windows else file_off

                f.seek(file_off)
                chunk = f.read(bb[1] - bb[0] + 1)

                md = Cs(CS_ARCH_X86, CS_MODE_64)

                out_f.write('\nL_{}:\n'.format(hex(bb[0])))
                for instr in md.disasm(chunk, bb[0]):
                    opcode = instr.mnemonic
                    next_addr = instr.address + instr.size

                    out_f.write("\t\t{}\t{}".format(instr.mnemonic, instr.op_str))

                    if 'ptr [rip +' in instr.op_str:
                        tmp_tokens = instr.op_str.split("]")[0].split()
                        offset_str = tmp_tokens[-1]
                        sign = tmp_tokens[-2]
                        if offset_str == "[rip":
                            offset_str = "0x0"
                            sign = "+"
                        offset = int(offset_str, 16)

                        if sign == "-":
                            abs_addr = next_addr - offset
                        else:
                            abs_addr = next_addr + offset

                        out_f.write(' #0x%x' % abs_addr)
                    out_f.write('\n')
                    
    return


def main():
    if len(sys.argv) != 5:
        usage()

    trace_log_file_name = sys.argv[1]
    orig_bin_file_name = sys.argv[2]
    output_assembly_file_name = sys.argv[3]
    callback_file_name = sys.argv[4]

    read_trace(trace_log_file_name, orig_bin_file_name)
    stitch(orig_bin_file_name, output_assembly_file_name, callback_file_name)

if __name__ == '__main__':
    main()
