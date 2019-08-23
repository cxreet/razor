#!/usr/bin/python
from __future__ import print_function
import os, sys, operator

"""
Merge a program's all trace to generate a new file,
which contains all the executed bbs, taken/non-taken
of all conditional branches, and targets of all 
indirect calls.
"""

MODULE_START = 0
MODULE_NAME = 0

def usage():
    print('python merge-log.py log-dir program-name\n')
    sys.exit(1)

def merge_log(log_dir, bin_name, trace_log_file_name=None):
    global MODULE_START
    global MODULE_NAME
    logs = []
    for fname in os.listdir(log_dir):
        if bin_name in fname:
            logs.append(os.path.join(log_dir, fname))
    
    executed_bbs = {}
    cond_brs = {}
    ind_calls = {}

    for log in logs:
        with open(log, 'r') as f:
            print('handling log ', log)
            for line in f.readlines():
                line = line.strip()
                tokens = line.split()

                if line.startswith("MODULE_START:"):
                    MODULE_START = int(tokens[-1], 16)

                elif line.startswith("MODULE_NAME"):
                    MODULE_NAME = tokens[1].strip()

                elif line.startswith('+B+:'):
                    start_addr = int(tokens[1], 16)
                    end_addr = int(tokens[2], 16)

                    if start_addr not in executed_bbs:
                        executed_bbs[start_addr] = end_addr

                elif line.startswith('+CND+'):
                    addr = int(tokens[1].split(':')[0], 16)
                    taken = tokens[2].strip()

                    bit = 0
                    if taken == 'taken':
                        bit = 1
                    elif taken.startswith('not'):
                        bit = 2
                    else:
                        bit = 3

                    if addr not in cond_brs:
                        cond_brs[addr] = bit
                    else:
                        cond_brs[addr] = cond_brs[addr] | bit
                    

                elif line.startswith('@'):
                    start_addr = int(tokens[0].split('@')[1], 16)
                    end_addr = int(tokens[2], 16)
                    freq = 0
                    if len(tokens) == 4:
                        freq = int(tokens[3])

                    if start_addr not in ind_calls:
                        ind_calls[start_addr] = {end_addr:freq}
                    else:
                        if end_addr not in ind_calls[start_addr]:
                            ind_calls[start_addr][end_addr] = freq
                        else:
                            ind_calls[start_addr][end_addr] += freq

                    continue
    
    if trace_log_file_name == None:
        trace_log_file_name = os.path.join(log_dir, '{}-trace.log'.format(bin_name))
    
    with open(trace_log_file_name, 'w') as out_f:
        out_f.write("MODULE_NAME: " + MODULE_NAME + "\n")
        out_f.write('MODULE_START: 0x%x\n' % MODULE_START)
        
        print('start mergin bbs')
        bb_list = []
        for bb in executed_bbs:
            bb_list.append((bb, executed_bbs[bb]))
        
        # remove duplicated blocks and sort by the start
        bb_list = list(set(bb_list))
        bb_list.sort(key=operator.itemgetter(0))

        new_bb_list = []
        last_added_bb_end_addr = 0
        for bb in bb_list:
            if last_added_bb_end_addr == 0:
                # first bb
                new_bb_list.append(bb)
                last_added_bb_end_addr = bb[1]
            else:
                if last_added_bb_end_addr < bb[0]:
                    # last addr smaller than the start
                    new_bb_list.append(bb)
                    last_added_bb_end_addr = bb[1]

                elif last_added_bb_end_addr < bb[1]:
                    # last addr is in the bb
                    new_bb_list.append((last_added_bb_end_addr + 1, bb[1]))
                    last_added_bb_end_addr = bb[1]
        
        bb_list = new_bb_list

        print('starts dumping out')
        for bb in bb_list:
            out_f.write('+B+ 0x%x 0x%x\n' % (bb[0], bb[1]))

        for cnd in cond_brs:
            out_f.write('+CND+ 0x%x %d\n' % (cnd, cond_brs[cnd]))

        for ind in ind_calls:
            out_f.write('+IND+ 0x%x ' % (ind))
            for tgt in ind_calls[ind]:
                out_f.write('0x%x#%d ' % (tgt, ind_calls[ind][tgt]))
            out_f.write('\n')

def main():
    if len(sys.argv) != 3:
        usage()

    bin_name = sys.argv[2]
    log_dir = sys.argv[1]
    
    merge_log(log_dir, bin_name)

if __name__ == '__main__':
    main()
