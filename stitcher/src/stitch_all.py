#!/usr/bin/python

import argparse
import os
import stitcher
import find_symbols
import merge_bin
import merge_log
import subprocess

INFER_PATH = True

def get_bin(trace):
    with open(trace, 'r') as f:
        for line in f.readlines():
            line = line.strip()
            if line.startswith("MODULE_NAME"):
                tokens = line.split()
                return tokens[1]

    return None

def execute(cmd):
    print cmd
    p = subprocess.Popen(cmd, shell=True)
    p.communicate()

def main():
    cwd = os.path.dirname(os.path.abspath(__file__))

    parser = argparse.ArgumentParser()
    parser.add_argument('-d', '--tracedir', nargs=1, help='the direcotry for log files')
    parser.add_argument('-b', '--binfile', nargs=1, help='the original binary file')
    args = parser.parse_args()

    log_dir = args.tracedir[0]
    orig_bin  = args.binfile[0]

    bin_name = os.path.basename(orig_bin)
    trace_log = bin_name + "-trace.log"
    raw_assembly = "instr-raw.s"
    final_assembly = "instr-final.s"
    callbacks = "callbacks.txt"

    merge_log.merge_log(log_dir, bin_name, trace_log)

    bin_path = get_bin(trace_log)

    # disassembling
    out_asm = bin_name + ".asm"
    cmd = "python %s/heuristic/disasm.py %s %s" % (cwd, bin_path, out_asm)
    execute(cmd)
    
    extended_log = trace_log.replace(".log", "-ext.log")
    if INFER_PATH:
        cmd = "python %s/heuristic/find_more_paths.py %s %s %s" % (cwd, out_asm, trace_log, extended_log)
        execute(cmd)
    
    if INFER_PATH:
        trace_log = extended_log

    stitcher.read_trace(trace_log, bin_path)
    stitcher.dump(bin_path, raw_assembly)
    find_symbols.find_symbols_for_plt(bin_path, raw_assembly, callbacks)
    stitcher.stitch(bin_path, final_assembly, callbacks)
    merge_bin.merge_bin_asm(bin_path, final_assembly)
    
if __name__ == "__main__":
    main()
