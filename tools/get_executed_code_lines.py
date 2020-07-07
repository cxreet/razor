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

def main():
    usage = "usage: %prog -t trace.log -b progrom_bin -s program_source_code -o output_file"
    parser = OptionParser(usage=usage)

    parser.add_option("-t", "--trace", dest="trace", help="The trace log.")
    parser.add_option("-b", "--bin", dest="bin", help="The program binary.")
    parser.add_option("-s", "--source", dest="source", help="The program source code.")
    parser.add_option("-o", "--output", dest="output", help="The output file.")
    (options, args) = parser.parse_args()

    trace = options.trace
    prog_bin = options.bin
    prog_source = options.source
    output_file = options.output

    if (not trace) or (not prog_bin) or (not prog_source) or (not output_file):
        parser.print_help()
        sys.exit(1)

    source_file_name = prog_source.split("/")[-1]
    
    # Get executed code using addr2line
    executed_code_line_numbers = set()
    executed_bbs = get_executed_bbs(trace)
    for (bb_start, bb_end) in executed_bbs:
        cmd = "addr2line -e %s %s %s" % (prog_bin, hex(bb_start), hex(bb_end))
        p = subprocess.Popen(cmd, shell=True, stdout=subprocess.PIPE)
        out = p.communicate()[0]
        line_min = -1
        line_max = -1
        for line in out.split("\n"):
            if source_file_name not in line:
                continue
            line = line.strip()
            try:
                code_line_number = int(line.split(":")[-1].split()[0])
                executed_code_line_numbers.add(code_line_number)
                if line_min == -1 or code_line_number < line_min:
                    line_min = code_line_number
                if line_max == -1 or code_line_number > line_max:
                    line_max = code_line_number
            except:
                pass
        
        if line_min != -1 and line_max != -1:
            for i in range(line_min, line_max+1):
                executed_code_line_numbers.add(i)
    
    line_numbers = sorted(list(executed_code_line_numbers))

    # Dump the executed code
    with open(prog_source, 'r') as in_f:
        lines = in_f.readlines()

        with open(output_file, 'w') as out_f:

            for i in range(0, len(lines)):
                if i in line_numbers:
                    out_f.write(lines[i][:-1] + " // +Yes " + "\n")
                else:
                    out_f.write(lines[i])

if __name__ == "__main__":
    main()
