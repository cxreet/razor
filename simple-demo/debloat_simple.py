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

    parser.add_option("-c", "--cmd", dest="cmd", help="The command: clean|build|trace|merge_log|dump_inst|instrument|rewrite")
    parser.add_option("-a", "--taken", dest="taken", help="The `taken` argument.")
    parser.add_option("-b", "--target", dest="target", help="The `target` argument.")
    (options, args) = parser.parse_args()

    cmd = options.cmd
    taken = options.taken
    target = options.target
    
    if not cmd:
        parser.print_help()
        sys.exit(1)

    elif cmd == "clean":
        cmd = "rm -rf logs simple simple_temp simple-trace.log callbacks.txt *.s"
        execute(cmd)

    elif cmd == "build":
        cmd = "gcc simple.c -O1 -o simple -no-pie"
        execute(cmd)

    elif cmd == "trace":
        if not taken or not target:
            parser.print_help()
            sys.exit(1)

        cmd = "../tracers/scripts/trace_with_dynamorio.sh ./simple %s %s" % (taken, target)
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
