#!/usr/bin/python

import sys

import stitcher

"""
python instr_dumper trace-*-*.txt exe out_exe.s
"""


def usage():
    print('python instr.py trace-*-*.txt exe out_exe.s')
    sys.exit(1)

def main():

    if len(sys.argv) != 4:
        usage()

    trace_log_file_name = sys.argv[1]
    orig_bin_file_name = sys.argv[2]
    output_assembly_file_name = sys.argv[3]

    stitcher.read_trace(trace_log_file_name, orig_bin_file_name)
    stitcher.dump(orig_bin_file_name, output_assembly_file_name)

if __name__ == '__main__':
    main()
