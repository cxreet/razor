#!/usr/bin/python
import os, sys, subprocess
from optparse import OptionParser

def execute(cmd):
    print cmd
    p = subprocess.Popen(cmd, shell=True, stdout=subprocess.PIPE)
    p.communicate()

def main():
    usage = "usage: %prog -a first_executed_code -b second_executed_code -o output_file"
    parser = OptionParser(usage=usage)
    
    # Get executed code that is in file_b but not in file_a.
    parser.add_option("-a", "--file_a", dest="file_a", help="First executed source code.")
    parser.add_option("-b", "--file_b", dest="file_b", help="Second executed source code.")
    parser.add_option("-o", "--output", dest="output", help="The output file.")
    (options, args) = parser.parse_args()
    
    file_a = options.file_a
    file_b = options.file_b
    output_file = options.output

    if (not file_a) or (not file_b) or (not output_file):
        parser.print_help()
        sys.exit(1)
    
    executed_code_1 = None
    with open(file_a, 'r') as in_f:
        executed_code_1 = in_f.readlines()

    executed_code_2 =None
    with open(file_b, 'r') as in_f:
        executed_code_2 = in_f.readlines()
    
    with open(output_file, 'w') as out_f:
        for i in range(0, len(executed_code_1)):
            line1 = executed_code_1[i]
            line2 = executed_code_2[i]
            
            if line2[:-2].endswith("+Yes") and (not line1[:-2].endswith("+Yes")):
                out_f.write(line2[:-2] + " Missing\n")
            else:
                out_f.write(line2)

if __name__ == "__main__":
    main()
