#!/usr/bin/python
from __future__ import print_function
import sys, subprocess, os, operator
import networkx as nx
import networkx.algorithms.cycles as cycles
import objdump as od
#import cfg_utils as cu
import json
import time
from bisect import bisect_left

"""
LEAST_CODE_LEVEL: the heuristic that won't introduce any new code, but it turns on
                  conditonal branches whose non-taken branch is reachable from other
                  sources. For example:
                    b1 --> b2, b2 --> b3, b2 --> b4, b1 --> b4. For conditional 
                    barnch at b2, only b2 --> b3 is executed, but b4 is reachable
                    from b1, so b2 --> b4 is turned on.

LEAST_CALL_LEVEL: the heuristic that won't introduce any new `call` instructions

LEAST_LIBCALL_LEVEL: the heuristic that won't introduce any new library functions

LEAST_PRIVCALL_LEVEL: the heuristic that won't introduce any sensitive library calls
"""
LEAST_CODE_LEVEL = 1
LEAST_CALL_LEVEL = 2
LEAST_LIBCALL_LEVEL = 3
LEAST_PRIVCALL_LEVEL = 4
HEURISTIC_LEVEL = 4
SENSITIVE_LIBCALLS = ['execl', 'execle', 'execlp', 'execv', 'execve', 'execvp']
LIBCALL_GROUPS = {}

# the threshold for path length
MAX_PATH_LENGTH = 32
MAX_PATH_NUM = 10000

MODULE_START = 0
g_executed_bbs = []
g_cnd_table = {}
g_diff_branches = []
g_indcalls = []
g_executed_insts = []
g_executed_libcalls = []
g_executed_libcall_groups = []

g_inferred_paths = []

g_func_libcalls = {}
g_func_new_funcs = {}

def usage():
    print('usage: python find_more_paths.py elf_binary trace.log out-extended.log')
    sys.exit(0)

def execute(cmd):
    p = subprocess.Popen(cmd, shell=True)
    p.communicate()

def read_traces():
    global g_executed_bbs, g_cnd_table, g_diff_branches, g_indcalls, MODULE_START
    fpath = sys.argv[2]

    with open(fpath, 'r') as trace:
        for line in trace.readlines():
            line = line.strip()
            tokens = line.split()

            if line.startswith('MODULE_START:'):
                MODULE_START = int(tokens[1], 16)
                continue

            if line.startswith('+B+'):
                bb_start = int(tokens[1], 16)
                bb_end = int(tokens[2], 16)
                """
                if bb_start not in g_executed_bbs:
                    g_executed_bbs.append((bb_start, bb_end))
                """
                g_executed_bbs.append((bb_start, bb_end))
                continue

            if line.startswith('+CND+'):
                cnd_addr = int(tokens[1], 16)
                taken_flag = int(tokens[2], 10)
                g_cnd_table[cnd_addr] = taken_flag
                
                """
                if cnd_addr not in g_cnd_table:
                    g_cnd_table[cnd_addr] = taken_flag
                else:
                    if g_cnd_table[cnd_addr] != taken_flag:
                        if cnd_addr not in g_diff_branches:
                            g_diff_branches.append(cnd_addr)
                    g_cnd_table[cnd_addr] |= taken_flag
                """

                continue
            
            if line.startswith('+IND+'):
                g_indcalls.append(line)

                continue

    # sort all the executed bbs
    g_executed_bbs.sort(key=operator.itemgetter(0))

# find all the executed instructions
def find_all_executed_insts():
    global g_executed_insts, g_executed_libcalls, g_executed_libcall_groups
    for bb in g_executed_bbs:
        s_addr = bb[0]
        e_addr = bb[1]
        
        addr = s_addr
        while addr <= e_addr:
            if addr in od.plt_entries:
                libcall_name = od.func_addr_name[addr].split('@plt')[0].split('<')[-1]
                if libcall_name not in g_executed_libcalls:
                    g_executed_libcalls.append(libcall_name)

                    for group in LIBCALL_GROUPS:
                        if libcall_name in LIBCALL_GROUPS[group]:
                            if group not in g_executed_libcall_groups:
                                g_executed_libcall_groups.append(group)

            g_executed_insts.append(addr)
            addr += od.inst_length[addr]

def dump_path(path):
    print('\npath: ')
    for n in path:
        print(hex(n), ' ')
    print('\n')

# find the paths with different taken info
def find_paths(func_addr, cfg, src, worklist, paths):
    """
    if src in g_executed_insts:
        print(hex(src))
        for wl in worklist:
            dump_path(wl)
    """
    assert(src not in g_executed_insts)
    
    # give up when the path is too long
    for wl in worklist:
        if len(wl) > MAX_PATH_LENGTH:
            return

    #print('src:', hex(src))

    if src not in cfg:
        return

    # find paths in cfg from `src` according to the `g_cnd_table`
    neighbors = []
    n1 = 0
    n2 = 0
    nodes = cfg[src]
    n1 = nodes[0]
    n2 = nodes[1]
    if n1 != 0:
        neighbors.append(n1)
    if n2 != 0:
        neighbors.append(n2)
    
    # for frame_dummy, never returns
    if len(neighbors) == 0:
        print('no neighbors 0x%x\n' % src)
        return

    if len(neighbors) == 1:

        if neighbors[0] in g_executed_insts:
            for wl in worklist:
                new_wl = wl[:]
                new_wl.append(neighbors[0])
                paths.append(new_wl)
        else:
            new_worklist = []
            for wl in worklist:
                new_wl = wl[:]
                if neighbors[0] not in wl:
                    new_wl.append(neighbors[0])
                    new_worklist.append(new_wl)

            if len(new_worklist) > 0:
                find_paths(func_addr, cfg, neighbors[0], new_worklist, paths)

    else:
        assert(len(neighbors) == 2)
        assert(src not in g_cnd_table)

        if neighbors[0] not in g_executed_insts:
            new_worklist = []
            # taken
            for wl in worklist:
                new_wl = wl[:]
                if neighbors[0] not in new_wl:
                    new_wl.append(neighbors[0])
                    new_worklist.append(new_wl)
            if len(new_worklist) > 0:
                find_paths(func_addr, cfg, neighbors[0], new_worklist, paths)
        else:
            for wl in worklist:
                new_wl = wl[:]
                new_wl.append(neighbors[0])
                paths.append(new_wl)

        
        if neighbors[1] not in g_executed_insts:
            new_worklist = []
            # not taken
            for wl in worklist:
                new_wl = wl[:]
                if neighbors[1] not in new_wl:
                    new_wl.append(neighbors[1])
                    new_worklist.append(new_wl)
            if len(new_worklist) > 0:
                find_paths(func_addr, cfg, neighbors[1], new_worklist, paths)
        else:
            for wl in worklist:
                new_wl = wl[:]
                new_wl.append(neighbors[1])
                paths.append(new_wl)


    return

def infer_paths():
    global g_inferred_paths, g_cnd_table
    
    cnd_list = []

    num_cnd_brs = 0
    for addr in g_cnd_table:
        taken_flag = g_cnd_table[addr]
        if taken_flag != 3:
            num_cnd_brs += 1
            cnd_list.append((addr, g_cnd_table[addr]))

    cnd_list = sorted(cnd_list, key=lambda tup: tup[0]) 

    old_cfg = None
    old_func_range = None
    idx = 0
    for p in cnd_list:
        addr = p[0]
        
        taken_flag = p[1]
        if taken_flag != 3:
            idx += 1

            print(idx, '/', num_cnd_brs)

            print('infer paths from ', hex(addr))
            
            cfg = None
            if old_func_range != None and addr >= old_func_range[0] and addr <= old_func_range[1]:
                cfg = old_cfg
            else:
                start_time = time.time()
                (func_addr, cfg) = od.get_cfg(addr)
                end_time = time.time()
                print('XXXX:', end_time - start_time)
                old_cfg = cfg
                old_func_range = od.func_ranges[func_addr]

            paths = []

            tgt = 0
            fallthrough = 0
            nodes = cfg[addr]
            tgt = nodes[0]
            fallthrough = nodes[1]
            
            print(hex(addr))
            assert(fallthrough != 0 and tgt != 0)

            if taken_flag == 1:
                # taken
                worklist = [[addr, fallthrough]]
                if fallthrough not in g_executed_insts:
                    # heuristic besides LEAST_CODE_LEVEL
                    if HEURISTIC_LEVEL != LEAST_CODE_LEVEL:
                        find_paths(func_addr, cfg, fallthrough, worklist, paths)
                else:
                    g_cnd_table[addr] = 3
                    print('0x%x is already executed\n' % fallthrough)
            elif taken_flag == 2:
                # not taken
                worklist = [[addr, tgt]]
                if tgt not in g_executed_insts:
                    if HEURISTIC_LEVEL != LEAST_CODE_LEVEL:
                        # heuristic besides LEAST_CODE_LEVEL
                        find_paths(func_addr, cfg, tgt, worklist, paths)
                else:
                    g_cnd_table[addr] = 3
                    print('0x%x is already executed\n' % tgt)

            print('inferred %d paths:' % len(paths))
            for path in paths:
                #dump_path(path)
                # check the path with heuristics
                print('checking path')
                to_include = check_path(path)
                print('done')
                if not to_include:
                    #print('ignore this path\n')
                    continue

                g_inferred_paths.append(path)
                """
                if len(g_inferred_paths) > MAX_PATH_NUM:
                    return
                """

    return


def merge_bbs(origin_bbs, inferred_bbs):
    bb_list = origin_bbs[:]

    for bbs in inferred_bbs:
        for bb in bbs:
            bb_list.append((bb[0], bb[1]))

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
    
    return new_bb_list


"""
Return a list of library calls trigerred by the function
"""
def check_function(func_addr, checked_funcs):
    global g_func_libcalls
    libcalls = []

    if func_addr in checked_funcs:
        if func_addr not in g_func_libcalls:
            g_func_libcalls[func_addr] = libcalls
        return libcalls
    
    # library call
    if func_addr in od.plt_entries:
        func_name = od.func_addr_name[func_addr]
        if func_name not in libcalls:
            libcalls.append(func_name)

        if func_addr not in g_func_libcalls:
            g_func_libcalls[func_addr] = libcalls
        return libcalls

    if func_addr in g_executed_insts:
        if func_addr not in g_func_libcalls:
            g_func_libcalls[func_addr] = libcalls
        return libcalls
    
    blocks = od.func_blocks[func_addr]
    for b in blocks:
        start_addr = b[0]
        end_addr = b[1]
        
        i = start_addr
        while i <= end_addr:
            ops = od.inst_ops[i]

            if ops[0].startswith('jmp') or ops[0].startswith('call'):
                tgt_addr = 0
                try:
                    tgt_addr = int(ops[1], 16)
                except:
                    tgt_addr = 0
                
                if tgt_addr != 0:
                    if tgt_addr in od.func_ranges:
                        checked_funcs.append(func_addr)
                        new_libcalls = None
                        if tgt_addr in g_func_libcalls:
                            new_libcalls = g_func_libcalls[tgt_addr]
                        else:
                            new_libcalls = check_function(tgt_addr, checked_funcs)

                        for new_libcall in new_libcalls:
                            if new_libcall not in libcalls:
                                libcalls.append(new_libcall)

            i += od.inst_length[i]
    
    if func_addr not in g_func_libcalls:
        g_func_libcalls[func_addr] = libcalls
    return libcalls


"""
Return False if the path invokes a libary call that
has not been executed before, and it's sensitive.
"""
def check_least_privilege(p):
    for inst_addr in p:
        ops = od.inst_ops[inst_addr]

        if ops[0].startswith('jmp') or ops[0].startswith('call'):
            tgt_addr = 0
            try:
                tgt_addr = int(ops[1], 16)
            except:
                tgt_addr = 0
            
            if tgt_addr in od.func_ranges:
                libcalls = None
                if tgt_addr in g_func_libcalls:
                    libcalls = g_func_libcalls[tgt_addr]
                else:
                    libcalls = check_function(tgt_addr, [])
                
                
                for libcall in libcalls:
                    func_start = od.func_name_addr[libcall]

                    if func_start not in g_executed_insts:
                        clean_libcall = libcall.split('@plt')[0].split('<')[-1]

                        """
                        if clean_libcall in SENSITIVE_LIBCALLS:
                            print("SENSITIVE LIB CALL\n")
                            return False

                        """
                
                        found = False
                        for group in LIBCALL_GROUPS:
                            if clean_libcall in LIBCALL_GROUPS[group]:
                                if group in g_executed_libcall_groups:
                                    print('Found same group: ', group, clean_libcall)
                                    found = True
                                    break

                        if found:
                            print('Allowed libcall: ', clean_libcall)
                        else:
                            print('Disallowed libcall: ', clean_libcall)
                            return False



    return True


"""
Return False if the path invokes a library call that
has not been executed before, or has indirect call/jump.
"""
def check_least_libcall(p):
    for inst_addr in p:
        ops = od.inst_ops[inst_addr]

        if ops[0].startswith('jmp') or ops[0].startswith('call'):
            tgt_addr = 0
            try:
                tgt_addr = int(ops[1], 16)
            except:
                tgt_addr = 0
            
            if tgt_addr in od.func_ranges:
                # a function
                libcalls = None
                if tgt_addr in g_func_libcalls:
                    libcalls = g_func_libcalls[tgt_addr]
                else:
                    libcalls = check_function(tgt_addr, [])

                for libcall in libcalls:
                    func_start = od.func_name_addr[libcall]

                    if func_start not in g_executed_insts:
                        return False

    return True


"""
Return False if the path has `call' instructions
"""
def check_least_call(p):
    for inst_addr in p:
        inst_len = od.inst_length[inst_addr]
        ops = od.inst_ops[inst_addr]

        if ops[0].startswith('call'):
            return False

    return True


# check whether the path introduces different functionality
def check_path(p):
    
    # first, filter out the path with indirect call/jmp
    for inst_addr in p:
        inst_len = od.inst_length[inst_addr]
        ops = od.inst_ops[inst_addr]

        if ops[0].startswith('jmp') or ops[0].startswith('call'):
            tgt_addr = 0
            try:
                tgt_addr = int(ops[1], 16)
            except:
                tgt_addr = 0

            if tgt_addr == 0:
                return False

    #check the path for different heuristics
    if HEURISTIC_LEVEL == LEAST_CALL_LEVEL:
        return check_least_call(p)
    
    if HEURISTIC_LEVEL == LEAST_LIBCALL_LEVEL:
        return check_least_libcall(p)
    
    if HEURISTIC_LEVEL == LEAST_PRIVCALL_LEVEL:
        return check_least_privilege(p)

    return False

# Returns the functions that have not been executed, but
# are triggered by function at `func_addr`.
def get_new_functions(func_addr, checked_funcs):
    global g_func_new_funcs

    new_funcs = []

    if func_addr in checked_funcs:
        if func_addr not in g_func_new_funcs:
            g_func_new_funcs[func_addr] = new_funcs
        return new_funcs
    
    if func_addr not in g_executed_insts:
        new_funcs.append(func_addr)

    if func_addr in od.plt_entries:
        if func_addr not in g_func_new_funcs:
            g_func_new_funcs[func_addr] = new_funcs
        return new_funcs
    
    blocks = od.func_blocks[func_addr]
    for b in blocks:
        start_addr = b[0]
        end_addr = b[1]
        
        i = start_addr
        while i <= end_addr:
            ops = od.inst_ops[i]

            if ops[0].startswith('jmp') or ops[0].startswith('call'):
                tgt_addr = 0
                try:
                    tgt_addr = int(ops[1], 16)
                except:
                    tgt_addr = 0
                
                if (tgt_addr in od.func_ranges) and (tgt_addr not in g_executed_insts):
                    checked_funcs.append(func_addr)
                    tmp_new_funcs = None
                    if tgt_addr in g_func_new_funcs:
                        tmp_new_funcs = g_func_new_funcs[tgt_addr]
                    else:
                        tmp_new_funcs = get_new_functions(tgt_addr, checked_funcs)
                    for new_func in tmp_new_funcs:
                        if new_func not in new_funcs:
                            new_funcs.append(new_func)

            i += od.inst_length[i]
    
    if func_addr not in g_func_new_funcs:
        g_func_new_funcs[func_addr] = new_funcs
    return new_funcs

def out_log():
    # handle the inferred paths
    bb_start = 0

    inferred_bbs = []
    inferred_cnd_table = {}
    
    print('getting new bbs...')
    for p in g_inferred_paths:
        (func_addr, cfg) = od.get_cfg(p[0])

        blocks = []
        path_len = len(p)

        for i in range(0, path_len):
            inst_addr = p[i]
            inst_len = od.inst_length[inst_addr]
            
            # reset bb_start
            if bb_start == 0:
                bb_start = inst_addr
            
            # the last node in the path
            if i == path_len - 1:
                blocks.append((bb_start, inst_addr + inst_len - 1))
                bb_start = 0
            else:
                # check whether the next instruction follows this
                next_inst = p[i+1]

                if inst_addr + inst_len != next_inst:
                    blocks.append((bb_start, inst_addr + inst_len - 1))
                    bb_start = 0

            # check conditional branches
            n1 = 0
            n2 = 0

            if inst_addr not in cfg:
                continue
            
            if inst_addr not in od.cnd_jmps:
                continue

            nodes = cfg[inst_addr]
            n1 = nodes[0]
            n2 = nodes[1]
            
            # conditional branch, check the next instruction
            # if it's conditional branch and the last instruction, it'd be handled
            # in another path
            if n1 > 0 and n2 > 0 and i < path_len - 1:
                if inst_addr not in inferred_cnd_table:
                    inferred_cnd_table[inst_addr] = 0

                next_inst = p[i+1]
                if next_inst == n1: # taken
                    inferred_cnd_table[inst_addr] |= 1
                elif next_inst == n2: # not taken
                    inferred_cnd_table[inst_addr] |= 2
                else:
                    assert(False)
        
        for b in blocks:
            assert(b[1] >= b[0])
            #print(hex(b[0]), hex(b[1]))
        inferred_bbs.append(blocks)
    
    print('adding new functions...')
    # add functions that have not been executed
    all_new_funcs = []
    total_path_num = len(g_inferred_paths)
    idx = 0

    for p in g_inferred_paths:
        idx += 1
        print(idx, '/', total_path_num)

        path_len = len(p)

        for i in range(0, path_len):
            inst_addr = p[i]
            ops = od.inst_ops[inst_addr]

            if ops[0].startswith('jmp') or ops[0].startswith('call'):
                tgt_addr = 0
                try:
                    tgt_addr = int(ops[1], 16)
                except:
                    tgt_addr = 0
                
                if (tgt_addr in od.func_ranges) and (tgt_addr not in g_executed_insts):
                    new_funcs = None
                    if tgt_addr in g_func_new_funcs:
                        new_funcs = g_func_new_funcs[tgt_addr]
                    else:
                        new_funcs = get_new_functions(tgt_addr, [])
                    for new_func in new_funcs:
                        if new_func not in all_new_funcs:
                            all_new_funcs.append(new_func)
    
    # merge the intra-procedual blocks
    print('merging bbs...')
    merged_bbs = merge_bbs(g_executed_bbs, inferred_bbs)

    # added the code in all new functions
    inferred_indcalls = {}
    for new_func in all_new_funcs:
        print('adding new function ', hex(new_func))
        blocks = od.func_blocks[new_func]

        # add blocks in new functions
        merged_bbs.extend(blocks)

        # add conditional branches in new functions
        for b in blocks:
            start_addr = b[0]
            end_addr = b[1]
        
            i = start_addr
            while i <= end_addr:
                if i in od.cnd_jmps:
                    inferred_cnd_table[i] = 3

                if i in od.ind_jmps:
                    inferred_indcalls[i] = i

                i += od.inst_length[i]

        # add new indirect jumps (i.e., the indirect jumps in plt entries)
        if new_func in od.plt_entries:
            inferred_indcalls[new_func] = new_func + 6
            print('NEW LIBCALL: ', od.func_addr_name[new_func])
    
    # sort the bbs last time
    merged_bbs.sort(key=operator.itemgetter(0))
    
    print('merging conditional branches...')
    # merge the conditional branch table
    new_cnd_table = {}
    for k in g_cnd_table:
        new_cnd_table[k] = g_cnd_table[k]
        if k in inferred_cnd_table:
            new_cnd_table[k] |= inferred_cnd_table[k]
    for k in inferred_cnd_table:
        if k not in new_cnd_table:
            new_cnd_table[k] = inferred_cnd_table[k]

    # write the original log to '.old.log'
    with open('.old.log', 'w') as old_log:
        old_log.write('MODULE_START: 0x%x\n' % MODULE_START)
        for b in g_executed_bbs:
            old_log.write('+B+ 0x%x 0x%x\n' % (b[0], b[1]))
    
    print('writing out...')
    # extend the log
    with open(sys.argv[3], 'w') as out_f:
        out_f.write('MODULE_START: 0x%x\n' % MODULE_START)
        for b in merged_bbs:
            out_f.write('+B+ 0x%x 0x%x\n' % (b[0], b[1]))

        for k in new_cnd_table:
            out_f.write('+CND+ 0x%x %d\n' % (k, new_cnd_table[k]))

        for line in g_indcalls:
            addr = int(line.split()[1], 16)
            out_f.write(line)
            if addr in od.plt_entries:
                out_f.write(' 0x7fffffffffff#1024')
            out_f.write('\n')

        
        for addr in inferred_indcalls:
            out_f.write('+IND+ ')
            out_f.write(hex(addr))
            out_f.write(' 0x%x#1' % inferred_indcalls[addr])
            out_f.write(' 0x7fffffffffff#1024\n')

    return

def main():
    global g_cnd_table, LIBCALL_GROUPS

    if len(sys.argv) != 4:
        usage()
    
    # set the recursion limit for deep searching
    sys.setrecursionlimit(10240)

    # read the libcall groups
    with open('/home/chenxiong/stitcher/static_analysis/libcall.groups', 'r') as f:
        LIBCALL_GROUPS = json.load(f)

    #print(LIBCALL_GROUPS)

    # read trace, initialize trace info globals
    print('reading trace')
    read_traces()
    
    # disassemble the binary
    cmd = 'objdump -d -w --insn-width=16 %s > .objdump.out' % (sys.argv[1])
    execute(cmd)
    
    print('reading objdump output...')
    # parse the objdump output to construct cfgs
    od.read_objdump()
    
    # remove .objdump.out
    cmd = 'rm .objdump.out'
    execute(cmd)

    # find loops
    #cu.find_loops(g_cnd_table)
    
    print('finding all executed instructions...')
    # find all executed instructions
    find_all_executed_insts()
    #print('executed lib calls: \n', g_executed_libcalls)
    
    # infer more paths
    print('inferring paths...')
    infer_paths()
    
    print('dumping new log...')
    # output the extended log
    out_log()

    print('Found all paths!\n')

if __name__ == '__main__':
    main()
