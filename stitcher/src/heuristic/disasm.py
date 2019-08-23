#!/usr/bin/python
import sys
import subprocess
from capstone import *

def execute(cmd):
    print cmd
    p = subprocess.Popen(cmd, shell=True, stdout=subprocess.PIPE)
    p.communicate()

def usage():
    print "python disasm.py binary outfile"
    sys.exit(1)

def get_load_base(binary):
    cmd = "readelf -lW " + binary
    p = subprocess.Popen(cmd, shell=True, stdout=subprocess.PIPE)
    out = p.communicate()[0]
    lines = out.split('\n')

    for line in lines:
        line = line.strip()
        if line.startswith("LOAD"):
            tokens = line.split()
            load_base = int(tokens[2], 16)
            return load_base

    assert False
    return None

def main():
    if len(sys.argv) != 3:
        usage()

    cmd = "objdump -d -w --insn-width=16 %s > .tmp.asm" % (sys.argv[1])
    execute(cmd)

    all_funcs = []

    cur_func_name = None
    is_plt = False
    addrs = []

    with open(".tmp.asm", 'r') as f:
        for line in f.readlines():
            line = line.strip()
            tokens = line.split()

            if line.endswith(">:"):

                if cur_func_name != None:
                    all_funcs.append((cur_func_name, addrs[0][0], addrs[-1][0] + addrs[-1][1] - 1, is_plt, addrs))
                    cur_func_name = None
                    is_plt = False
                    addrs = []

                cur_func_name = line.split(">")[0].split("@")[0].split("<")[-1]
                is_plt = False
                if line.endswith("@plt>:"):
                    is_plt = True
            
            elif len(tokens) > 0 and tokens[0].endswith(":"):
                addr = 0
                try:
                    addr = int("0x" + tokens[0].split(":")[0], 16)
                    length = len(line[:57].strip().split()) - 1
                except:
                    pass

                if addr > 0:
                    addrs.append((addr, length))
            else:
                if cur_func_name != None:
                    all_funcs.append((cur_func_name, addrs[0][0], addrs[-1][0] + addrs[-1][1] - 1, is_plt, addrs))
                    cur_func_name = None
                    is_plt = False
                    addrs = []

        if cur_func_name != None:
            all_funcs.append((cur_func_name, addrs[0][0], addrs[-1][0] + addrs[-1][1] - 1, is_plt, addrs))
            cur_func_name = None
            is_plt = False
            addrs = []


    cmd = "rm .tmp.asm"
    execute(cmd)
    
    with open(sys.argv[2], 'w') as out_f:
        load_base = get_load_base(sys.argv[1])

        with open(sys.argv[1], 'rb') as in_f:
            for p in all_funcs:
                func_name = p[0]
                func_start = p[1]
                func_end = p[2]
                is_plt = p[3]
                addrs = p[4]

                out_f.write("F: %s 0x%x 0x%x %s\n" % (func_name, func_start, func_end, is_plt))
                for (addr, length) in addrs:
                    file_off = addr - load_base

                    in_f.seek(file_off)
                    raw_bytes = in_f.read(length)
                    md = Cs(CS_ARCH_X86, CS_MODE_64)
                    md.syntax = CS_OPT_SYNTAX_INTEL

                    for insn in md.disasm(raw_bytes, addr):
                        opcode = insn.mnemonic
                
                        s = "0x%x %s %d " % (insn.address, opcode, insn.size)
                        s += " ||" + insn.op_str
                
                        s += "\n"
                        out_f.write(s)

if __name__ == "__main__":
    main()
