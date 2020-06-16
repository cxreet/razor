#!/usr/bin/env python

import os
import sys
import argparse
import subprocess
from elf_basic import *

sys.dont_write_bytecode = True

libcall_list_name = "libcall.list"
eb = None
label2pltname = {}
arg2regTable = ["di",
                "si",
                "dx",
                "cx",
                "r8",
                "r9"]

def arg2reg(index):
    index -= 1
    if index < 0 or index >= len(arg2regTable):
        print "index %d is larger than arg2regTable size" % index
        exit(1)
    return arg2regTable[index]

def get_libcall_list():
    libcall_list = {}
    dir_path = os.path.dirname(os.path.abspath(__file__)) 
    libcall_list_path = dir_path + "/" + libcall_list_name
    with open(libcall_list_path, "r") as libcall_file:
        for line in libcall_file:
            line = line.strip().split(',')
            libcall_list[line[0]] = map(int, line[1:])

    #print libcall_list
    return libcall_list


def get_next_bb(asm_file):
    instrs = []
    while True:
        instr = asm_file.readline()
        
        if instr == "":
            # end of file
            return instrs
        elif instr == "\n":
            if len(instrs) != 0:
                return instrs
            else:
                continue
        else:
            instrs.append(instr.strip())

def find_symbols_for_plt(binname, asmname, callbacks_file_name="callbacks.txt"):
    global eb, label2pltname

    eb = elf_basic()
    libcalls = get_libcall_list()
    
    # Previously, we only handled functions pointers that are passed to .plt 
    # functions. Now, we also handle functions like `atexit` that are not in .plt.
    cmd = "objdump -d %s > ./.%s.asm" % (binname, binname)
    p = subprocess.Popen(cmd, shell=True)
    p.communicate()
    function_address_2_name = dict()
    with open("./.%s.asm" % (binname), 'r') as in_f:
        for line in in_f.readlines():
            line = line.strip()
            if not line.endswith(">:"):
                continue
            tokens = line.split()
            addr = int("0x%s" % (tokens[0]), 16)
            function_name = tokens[1].split(">")[0].split("<")[-1]
            if function_name in libcalls:
                function_address_2_name[addr] = function_name

    callbacks_file = open(callbacks_file_name, "w")

    got_addr = eb.read_dynamic_option(binname, DYNAMIC.DT_PLTGOT)
    got_1_addr = got_addr + ARCH.INT_SIZE
    got_2_addr = got_addr + ARCH.INT_SIZE * 2
    #print hex(got_2_addr)

    # find the plt implementation
    with open(asmname, "r") as asm_file:
        got_2_addr_str = "0x%lx" % got_2_addr
        #print got_2_addr_str
        bb = get_next_bb(asm_file)
        plt_impl_bb_addr = None
        while len(bb) > 0:
            label = bb[0]
            for instr in bb[1:]:
                if got_2_addr_str in instr:
                    plt_impl_bb_addr = label[2:-1]
                    break
            if plt_impl_bb_addr != None:
                break
            else:
                bb = get_next_bb(asm_file)

    #print plt_impl_bb_addr

    relocations_in_rela_plt = eb.get_relocation_info(binname)

    # find all plt functions
    with open(asmname, "r") as asm_file:
        bb = get_next_bb(asm_file)
        old_bb = bb
        while len(bb) > 0:
            label = bb[0]
            for instr in bb[1:]:
                if plt_impl_bb_addr in instr:
                    # should be like
                    # 
                    # pre_label:
                    #       jmp qword ptr [rip + 0x7ba79a] #0xbbd040
                    #
                    # label:
                    #       push  5
                    #       jmp plt_impl_bb_addr
                    #
                    assert(len(bb) == 3)
                    offset = bb[1].split()[1]
                    old_label = old_bb[0][:-1]
                    plt_name = relocations_in_rela_plt[int(offset, 16)]["name"].split('@')[0]
                    if plt_name in libcalls:
                        label2pltname[old_label] = plt_name
            old_bb = bb
            bb = get_next_bb(asm_file)

    for addr in function_address_2_name:
        old_label = "L_0x%x" % (addr)
        label2pltname[old_label] = function_address_2_name[addr]

    pattern = re.compile(r"(?P<opcode>mov[abs]*)\t"
                          "(?P<reg>[erabcdspxil0-589w]{2,3}), "
                          "(?P<imm>[0x0-9a-f]{1,16})$")

    # find call instructions of PLT entries
    with open(asmname, "r") as asm_file:
        bb = get_next_bb(asm_file)
        while len(bb) > 0:
            label = bb[0][:-1]
            # based on chexiong, a call will terminate one bb,
            # so we just have to care about the last instruction
            instr = bb[-1]
            if "call" in instr or "jmp" in instr:
                callee = instr.strip().split('\t')[1]
                if callee.startswith("0x"):
                    callee = "L_" + callee
                    if callee in label2pltname:
                        # ok, you are calling some interesting lib functions that use function address
                        # let me tell you how to fix it
                        arguments = map(arg2reg, libcalls[label2pltname[callee]])
                        arg_done = {}
                        # for every instruction (backwards)
                        for index in xrange(len(bb)-1, 0, -1):
                            # for every interesting argument
                            for arg in arguments:
                                # if not resolved yet
                                if arg in arg_done:
                                    continue
                                instr = bb[index]
                                m = pattern.match(instr)
                                if m != None and arg in instr:
                                    #print "matched", instr
                                    #print m.group("imm")
                                    print label, index
                                    callbacks_file.write(label + " " + str(index) + "\n")
                                    arg_done[arg] = 0

                        for arg in arguments:
                            if not arg in arg_done:
                                print >> sys.stderr, "Warnning: the " + str(arg) + " argument of " + label2pltname[callee] + " cannot be found"
                                print >> sys.stderr, "          called at"
                                for line in bb:
                                    print >> sys.stderr, "          ", line


            bb = get_next_bb(asm_file)

    callbacks_file.close()

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('binfile', nargs=1)
    parser.add_argument('asmfile', nargs=1)
    args = parser.parse_args()

    orig_bin_path = args.binfile[0]
    orig_asm_path = args.asmfile[0]

    find_symbols_for_plt(orig_bin_path, orig_asm_path)

    return

if __name__ == "__main__":
    main()
