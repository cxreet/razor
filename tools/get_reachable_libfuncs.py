#!/usr/bin/python
import os, sys, subprocess
from optparse import OptionParser

def execute(cmd):
    print cmd
    p = subprocess.Popen(cmd, shell=True, stdout=subprocess.PIPE)
    p.communicate()

"""
Get executed basic blocks.
"""
def get_executed_bbs(trace):
    executed_bbs = set()

    with open(trace, 'r') as in_f:
        for line in in_f.readlines():
            line = line.strip()
            if not line.startswith("+B+"):
                continue
            tokens = line.split()
            bb_start = int(tokens[-2], 16)
            bb_end = int(tokens[-1], 16)
            executed_bbs.add((bb_start, bb_end))

    return executed_bbs

# Get all reachable functions from the start address
def get_reachable_libfuncs_from(start_addr, simple_cg, all_libfuncs, visited):
    lib_funcs = set()

    visited.add(start_addr)

    for callee_addr in simple_cg[start_addr]:
        if callee_addr in all_libfuncs:
            # a lib call
            lib_funcs.add(callee_addr)
        else:
            if callee_addr in visited:
                continue
            else:
                # a new non-lib function
                tmp_lib_funcs = get_reachable_libfuncs_from(callee_addr, simple_cg, all_libfuncs, visited)
                for func in tmp_lib_funcs:
                    lib_funcs.add(func)

    return lib_funcs



def get_executed_libfuncs(bbs, simple_cg, all_libfuncs):
    executed_libfuncs = set()
    
    for (bb_start, bb_end) in bbs:
        if bb_start in simple_cg:
            if bb_start in all_libfuncs:
                executed_libfuncs.add(bb_start)
            else:
                visited = set()
                lib_funcs = get_reachable_libfuncs_from(bb_start, simple_cg, all_libfuncs, visited)
                for lib_func in lib_funcs:
                    executed_libfuncs.add(lib_func)

    return executed_libfuncs

"""
Get reachable library functions according to the trace.
"""
def main():
    usage = "usage: %prog -t trace_file -e binary -o output"
    parser = OptionParser(usage=usage)
    
    parser.add_option("-t", "--trace", dest="trace", help="The trace file.")
    parser.add_option("-e", "--bin", dest="bin", help="The executable binary.")
    parser.add_option("-o", "--output", dest="output", help="The output file.")
    (options, args) = parser.parse_args()
    
    trace = options.trace
    bin_file = options.bin
    output_file = options.output

    if (not trace) or (not bin_file) or (not output_file):
        parser.print_help()
        sys.exit(1)
    
    cur_dir = os.path.dirname(os.path.abspath(__file__))
    cmd = "python " + cur_dir + "/../stitcher/src/heuristic/disasm.py " + bin_file + " " + cur_dir + "/.tmp.asm"
    execute(cmd)

    # Get all lib functions in the binary
    all_libfuncs = dict()
    with open(cur_dir + "/.tmp.asm", 'r') as in_f:
        for line in in_f.readlines():
            line = line.strip()
            if not line.endswith("True"):
                continue
            tokens = line.split()
            all_libfuncs[int(tokens[2], 16)] = tokens[1]

    # Get simple call graph
    simple_cg = dict()
    with open(cur_dir + "/.tmp.asm", 'r') as in_f:
        cur_func_addr = None
        for line in in_f.readlines():
            line = line.strip()

            if line.startswith("F:"):
                if line.endswith("False"):
                    tokens = line.split()
                    func_addr = int(tokens[2], 16)
                    cur_func_addr = func_addr
                    simple_cg[cur_func_addr] = set()
                else:
                    cur_func_addr = None

            else:
                tokens = line.split()
                if tokens[1].startswith("call"):
                    try:
                        callee_addr = int(tokens[-1].split("||")[-1], 16)
                        if cur_func_addr:
                            simple_cg[cur_func_addr].add(callee_addr)

                    except:
                        pass

    
    cmd = "rm " + cur_dir + "/.tmp.asm"
    execute(cmd)

    bbs = get_executed_bbs(trace)

    executed_libfuncs = get_executed_libfuncs(bbs, simple_cg, all_libfuncs)
    
    with open(output_file, 'w') as out_f:
        for func_addr in executed_libfuncs:
            out_f.write(all_libfuncs[func_addr] + "\n")


if __name__ == "__main__":
    main()
