#!/usr/bin/python
import os, sys, subprocess
from optparse import OptionParser

def execute(cmd):
    print cmd
    p = subprocess.Popen(cmd, shell=True, stdout=subprocess.PIPE)
    p.communicate()

def main():
    usage = "usage: %prog cmd arg1 arg2"
    parser = OptionParser(usage=usage)

    parser.add_option("-c", "--cmd", dest="cmd", help="The command: clean|trace|merge_log|dump_inst|instrument|rewrite")
    parser.add_option("-a", "--a", dest="a", help="The `a` argument.")
    parser.add_option("-b", "--b", dest="b", help="The `b` argument.")
    (options, args) = parser.parse_args()

    cmd = options.cmd
    a = options.a
    b = options.b
    
    if not cmd:
        parser.print_help()
        sys.exit(1)

    elif cmd == "clean":
        cmd = "rm -rf logs simple_temp simple-trace.log simple.asm simple-extended.log callbacks.txt *.s"
        execute(cmd)

    elif cmd == "trace":
        if not a or not b:
            parser.print_help()
            sys.exit(1)

        cmd = "../tracers/scripts/trace_with_dynamorio.sh ./simple %s %s" % (a, b)
        execute(cmd)

        cmd = "mkdir -p logs; mv *.log logs/"
        execute(cmd)

    elif cmd == "merge_log":
        cmd = "python ../stitcher/src/merge_log.py ./logs simple"
        execute(cmd)
        cmd = "mv logs/simple-trace.log ./"
        execute(cmd)

    elif cmd == "dump_inst":
        cmd = "python ../stitcher/src/instr_dumper.py ./simple-trace.log ./simple ./instr.s"
        execute(cmd)

    elif cmd == "instrument":
        cmd = "python ../stitcher/src/find_symbols.py ./simple ./instr.s"
        execute(cmd)
        cmd = "python ../stitcher/src/stitcher.py ./simple-trace.log ./simple ./simple.s ./callbacks.txt"
        execute(cmd)

    elif cmd == "rewrite":
        cmd = "python ../stitcher/src/merge_bin.py simple simple.s"
        execute(cmd)
    
    else:
        parser.print_help()
        sys.exit(1)

    return

if __name__ == "__main__":
    main()
