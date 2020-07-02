#!/usr/bin/python
import sys, json, os, operator
from binfile import *
import subprocess

LEAST_CODE_LEVEL = 1
LEAST_CALL_LEVEL = 2
LEAST_LIBCALL_LEVEL = 3
LEAST_PRIVCALL_LEVEL = 4
HEURISTIC_LEVEL = 3
HEURISTIC_STATIC_CFG = False
FIND_FUNCTION_RECURSIVELY = True
LOOP_ITE_NUM = 2
#SENSITIVE_LIBCALLS = ['execl', 'execle', 'execlp', 'execv', 'execve', 'execvp']
LIBCALL_GROUPS = {}

OBJ_FILE = None
IS_MAIN_BINARY = True
MODULE_START = 0
EXE_START = 0
EXE_END = 0

EXECUTED_BBS = []
CND_TABLE = {}
IND_CALL_LINES = []
IND_CALL_2_TGTS = {}
EXECUTED_LIB_FUNCS = []

# the threshold for path length
MAX_PATH_LENGTH = 64

INFERRED_IND_TGTS = {}
ALL_PATHS = []

def usage():
    print "usage: python find_more_paths.py bin.asm trace.log out-extended.log heuristic_level[1,2,3,4]"
    sys.exit(0)

def is_addr_executed(addr):
    l = 0
    h = len(EXECUTED_BBS) - 1
    
    while l <= h:
        m = (l + h) / 2
        bb = EXECUTED_BBS[m]

        if addr > bb.end_addr:
            l = m + 1
        elif addr < bb.start_addr:
            h = m - 1
        else:
            return True

    if l == h:
        bb = EXECUTED_BBS[l]

        if addr >= bb.start_addr and addr <= bb.end_addr:
            return True

    return False


def read_trace(trace_file):
    global MODULE_START
    global EXECUTED_BBS
    global CND_TABLE
    global IND_CALL_LINES
    global IND_CALL_2_TGTS
    global EXECUTED_LIB_FUNCS

    obj_file = None
    
    func = None
    with open(trace_file, "r") as f:
        for line in f.readlines():
            line = line.strip()
            tokens = line.split()

            if line.startswith('MODULE_NAME:'):
                obj_file = BinFile(tokens[1], sys.argv[1])
                continue

            if line.startswith("MODULE_START:"):
                MODULE_START = int(tokens[1], 16)
                continue
            
            if line.startswith('+B+'):
                bb_start = int(tokens[1], 16)
                bb_end = int(tokens[2], 16)

                addr = bb_start
                while addr <= bb_end:
                    if func == None:
                        func = obj_file.find_func_with_inst_addr(addr)

                    assert func != None
                    if not func.in_func(addr):
                        func = obj_file.find_func_with_inst_addr(addr)
                    
                    func.is_executed = True
                    callees = func.callees
                    for callee in callees:
                        if callee.is_plt and (callee not in EXECUTED_LIB_FUNCS):
                            EXECUTED_LIB_FUNCS.append(callee)

                    if addr in func.blocks:
                        basic_block = func.blocks[addr]
                        basic_block.is_executed = True
                        basic_block.is_included = True
                        EXECUTED_BBS.append(basic_block)
                        addr = basic_block.end_addr + 1
                    else:
                        basic_block = func.find_block_contains(addr)
                        if basic_block == None:
                            print hex(func.func_start), hex(func.func_end), hex(addr), hex(bb_start), hex(bb_end)
                        basic_block.is_executed = True
                        basic_block.is_included = True
                        EXECUTED_BBS.append(basic_block)
                        addr = basic_block.end_addr + 1

                continue
    
            if line.startswith('+CND+'):
                cnd_addr = int(tokens[1], 16)
                func = obj_file.find_func_with_inst_addr(cnd_addr)
                if cnd_addr not in func.inst_map:
                    print "WARN: skip BAD conditional branch ", hex(cnd_addr)
                    continue
                taken_flag = int(tokens[2], 10)
                CND_TABLE[cnd_addr] = taken_flag
                continue

            if line.startswith('+IND+'):
                IND_CALL_LINES.append(line)

                tokens = line.strip().split()
                src_addr = int(tokens[1], 16)

                func = obj_file.find_func_with_inst_addr(src_addr)
                if src_addr not in func.inst_map:
                    print "WARN: skip BAD indirect call ", hex(src_addr)
                    continue

                if src_addr not in IND_CALL_2_TGTS:
                    IND_CALL_2_TGTS[src_addr] = []

                for token in tokens[2:]:
                    tgt_offset = int(token.split("#")[0], 16)
                    IND_CALL_2_TGTS[src_addr].append(tgt_offset)

                continue
    
    return obj_file

def check_least_call(bb):
    func = bb.func
    succ_bbs = bb.succ_bbs

    for succ_bb in succ_bbs:
        if succ_bb.start_addr not in func.blocks:
            return False

    return True

def check_least_libcall(bb):
    func = bb.func

    for callee in func.callees:
        if callee.is_plt and (callee not in EXECUTED_LIB_FUNCS):
            return False

    return True

def check_least_privilege(bb):
    # TODO
    return True

# check whether the path introduces different functionality
def check_bb(bb):
    # patch: for this function, too many if-else, the path inferring gets
    # stuck.
    if bb.func.func_start == 0x413400:
        return True

    if HEURISTIC_STATIC_CFG:
        return True
    
    if HEURISTIC_LEVEL == LEAST_CALL_LEVEL:
        return check_least_call(bb)

    if HEURISTIC_LEVEL == LEAST_LIBCALL_LEVEL:
        return check_least_libcall(bb)

    if HEURISTIC_LEVEL == LEAST_PRIVCALL_LEVEL:
        return check_least_privilege(bb)

    return False

def traversal_from(func, basic_block, cur_path, all_paths):
    if basic_block.is_on_blacklist:
        return

    if not check_bb(basic_block):
        basic_block.is_on_blacklist = True
        return

    debug = False

    #print hex(basic_block.start_addr), len(cur_path), len(all_paths)

    if len(basic_block.succ_bbs) == 0:
        # no successors
        for bb in cur_path:
            bb.is_included = True
        all_paths.append(cur_path)
        #print len(all_paths)
        return
    
    all_on_blacklist = True
    for succ_bb in basic_block.succ_bbs:
        if not succ_bb.is_on_blacklist:
            all_on_blacklist = False
            break

    if all_on_blacklist:
        basic_block.is_on_blacklist = True
        return


    for succ_bb in basic_block.succ_bbs:
        if succ_bb.is_on_blacklist:
            continue

        if debug:
            print hex(succ_bb.start_addr)
    
        if succ_bb.is_included:
            # merge with included block
            for bb in cur_path:
                bb.is_included = True
            all_paths.append(cur_path)
            #print len(all_paths)
        else:
            
            # if it jumps to outside the function, don't follow it
            if not func.in_func(succ_bb.start_addr):
                #print "outside", hex(basic_block.start_addr), "-->", hex(succ_bb.start_addr)
                continue

            n = 0
            for tmp_bb in cur_path:
                if tmp_bb == succ_bb:
                    n += 1
            
            # skip the loop more than one iteration
            if n < LOOP_ITE_NUM:
                new_path = cur_path[:]
                new_path.append(succ_bb)
                
                traversal_from(func, succ_bb, new_path, all_paths)
            else:
                #print "skip loop"
                pass

    return

def infer_paths_from_cnd_branch():
    global CND_TABLE
    global ALL_PATHS

    cnd_list = []
    for addr in CND_TABLE:
        taken_flag = CND_TABLE[addr]
        if taken_flag != 3:
            cnd_list.append((addr, CND_TABLE[addr]))
    cnd_list = sorted(cnd_list, key=lambda tup: tup[0])
    
    cnd_num = len(cnd_list)
    func = None
    idx = 0
    for p in cnd_list:
        idx += 1
        #print idx, "/", cnd_num
        addr = p[0]
        taken_flag = p[1]
        
        if func == None:
            func = OBJ_FILE.find_func_with_inst_addr(addr)
        
        if not func.in_func(addr):
            func = OBJ_FILE.find_func_with_inst_addr(addr)

        basic_block = func.find_block_contains(addr)
        taken_bb = basic_block.succ_bbs[0]
        non_taken_bb = basic_block.succ_bbs[1]

        if taken_flag == 1:
            if non_taken_bb.is_executed == True:
                CND_TABLE[addr] = 3
            else:
                #print "CND@", hex(non_taken_bb.start_addr)
                cur_path = [non_taken_bb]
                paths = []
                traversal_from(func, non_taken_bb, cur_path, paths)
                #print len(paths), "paths"
                for p in paths:
                    ALL_PATHS.append(p)

                if len(paths) > 0:
                    CND_TABLE[addr] = 3

        elif taken_flag == 2:
            if taken_bb.is_executed == True:
                CND_TABLE[addr] = 3
            else:
                #print "CND@", hex(taken_bb.start_addr)
                cur_path = [taken_bb]
                paths = []
                traversal_from(func, taken_bb, cur_path, paths)
                #print len(paths), "paths"
                for p in paths:
                    ALL_PATHS.append(p)

                if len(paths) > 0:
                    CND_TABLE[addr] = 3

    return

def infer_paths_from_ind_call():
    global ALL_PATHS
    global INFERRED_IND_TGTS

    for src_addr in IND_CALL_2_TGTS:
        executed_tgts = IND_CALL_2_TGTS[src_addr]
        func = OBJ_FILE.find_func_with_inst_addr(src_addr)
        src_bb = func.find_block_contains(src_addr)
        end_inst = src_bb.end_inst
        
        # Bug: syscall instruction would have INDCALL# in the trace file
        assert end_inst.is_indirect_call or end_inst.is_indirect_jmp or end_inst.is_syscall
        
        # get the inside targets
        executed_inside_tgts = []
        for tgt in executed_tgts:
            if tgt >= EXE_START and tgt <= EXE_END:
                executed_inside_tgts.append(tgt)
        
        for succ_block in src_bb.succ_bbs:
            tgt = succ_block.start_addr
            if tgt not in executed_inside_tgts:
                if src_addr not in INFERRED_IND_TGTS:
                    INFERRED_IND_TGTS[src_addr] = []

                if tgt not in INFERRED_IND_TGTS[src_addr]:
                    INFERRED_IND_TGTS[src_addr].append(tgt)

            if not succ_block.is_executed:
                if func.in_func(tgt):
                    #print "IND@", hex(src_addr), "-->", hex(tgt)
                    cur_path = [succ_block]
                    paths = []
                    traversal_from(func, succ_block, cur_path, paths)
                    #print len(paths), "paths"
                    for p in paths:
                        ALL_PATHS.append(p)
                else:
                    # the target is in other function
                    pass



def merge_bbs(origin_bbs, inferred_bbs):
    print "merging bbs..."
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

def find_new_functions_recursively(new_functions):

    checked_funcs = []

    while True:

        old_size = len(new_functions)

        for new_func in new_functions:

            if new_func in checked_funcs:
                continue

            checked_funcs.append(new_func)

            for callee in new_func.callees:
                if (not callee.is_executed) and (callee not in new_functions):
                    new_functions.append(callee)

        new_size = len(new_functions)
        
        if new_size == old_size:
            break

    return


def patch_new_functions():
    ret = []
    # to add functions: 0x4224d0
    addrs = [0x4224d0, 0x425830, 0x409960, 0x412990, 0x405c30, 0x405b70, 0x4310c4,
             0x40d070, 0x422ee0, 0x424850, 0x422ef0, 0x423bb0, 0x424150, 0x423900,
             0x422f60, 0x4235c0, 0x424020, 0x412b60, 0x424580, 0x4256d0, 0x412bd0,
             0x426eb0, 0x412560]

    for addr in addrs:
        func = OBJ_FILE.find_func_with_inst_addr(addr)
        ret.append(func)

    return ret

def generate_extended_trace(paths):
    new_functions = []
    new_bbs = []
    new_cnd_table = {}
    # used only for plt entries
    new_plt_ind_call_table = {}
    new_ind_call_insts = []
    
    # get new bbs from the inferred paths
    print "collecting bbs from inferred paths..."
    for p in paths:
        func = p[0].func
        
        bb_start = 0
        blocks = []

        for bb in p:
            blocks.append((bb.start_addr, bb.end_addr))

            end_inst = bb.end_inst

            # new indirect call
            if end_inst.is_indirect_jmp or end_inst.is_indirect_call:
                if end_inst not in new_ind_call_insts:
                    new_ind_call_insts.append(end_inst)

            # new conditonal branch
            if end_inst.is_cond_jmp:
                taken_bb = bb.succ_bbs[0]
                non_taken_bb = bb.succ_bbs[1]
                
                if end_inst.addr not in new_cnd_table:
                    new_cnd_table[end_inst.addr] = 0
                if taken_bb.is_included:
                    new_cnd_table[end_inst.addr] |= 1
                if non_taken_bb.is_included:
                    new_cnd_table[end_inst.addr] |= 2

        new_bbs.append(blocks)
    
    # get all new functions
    print "collecting new functions..."
    for p in paths:
        func = p[0].func
        
        for bb in p:

            for succ_bb in bb.succ_bbs:
                new_func = succ_bb.func
                
                if not new_func.is_executed:
                    new_functions.append(new_func)
    
    # PATCH: add non-traced functions
    """
    for func in patch_new_functions():
        if func not in new_functions and (not func.is_executed):
            new_functions.append(func)
    """
    
    new_functions = list(set(new_functions))
    
    print len(new_functions), "new functions"
    if FIND_FUNCTION_RECURSIVELY:
        find_new_functions_recursively(new_functions)
    print len(new_functions), "new functions"

    # get new blocks in the new functions
    for new_func in new_functions:
        blocks = new_func.blocks
        temp_bbs = []
        for bb_addr in blocks:
            bb = blocks[bb_addr]
            assert not bb.is_executed
            temp_bbs.append((bb.start_addr, bb.end_addr))
        new_bbs.append(temp_bbs)
        
        for inst in new_func.insts:
            # add the conditional branches
            if inst.is_cond_jmp:
                new_cnd_table[inst.addr] = 3

            # indirect call or jump
            if (inst.is_indirect_jmp or inst.is_indirect_call):
                if inst not in new_ind_call_insts:
                    new_ind_call_insts.append(inst)
              
        # plt function
        if new_func.func_start in OBJ_FILE.plt_entries:
            new_plt_ind_call_table[new_func.func_start] = new_func.func_start + 6
    
    # merge conditional branches
    for addr in CND_TABLE:
        if addr not in new_cnd_table:
            new_cnd_table[addr] = CND_TABLE[addr]
        else:
            new_cnd_table[addr] |= CND_TABLE[addr]
    
    executed_bbs = []
    for bb in EXECUTED_BBS:
        executed_bbs.append((bb.start_addr, bb.end_addr))
    merged_bbs = merge_bbs(executed_bbs, new_bbs)
    
    print "generating extended traces..."
    with open(sys.argv[3], "w") as out_f:
        out_f.write("MODULE_START: 0x%x\n" % (MODULE_START))
        for b in merged_bbs:
            out_f.write('+B+ 0x%x 0x%x\n' % (b[0], b[1]))

        for k in new_cnd_table:
            out_f.write('+CND+ 0x%x %d\n' % (k, new_cnd_table[k]))

        for line in IND_CALL_LINES:
            out_f.write(line)
            
            if line.startswith("+IND+"):
                addr = int(line.split()[1], 16)
            
                if addr in INFERRED_IND_TGTS:
                    for tgt in INFERRED_IND_TGTS[addr]:
                        out_f.write(' ')
                        out_f.write("0x%x#1" % (tgt))
            out_f.write('\n')

        for addr in new_plt_ind_call_table:
            out_f.write('+IND+ ')
            out_f.write(hex(addr))
            out_f.write(' 0x%x#1' % (new_plt_ind_call_table[addr]))
            out_f.write('\n')

        for inst in new_ind_call_insts:
            if len(inst.ind_targets) > 0:
                out_f.write("+IND+ ")
                out_f.write(hex(inst.addr))

                for tgt in inst.ind_targets:
                    out_f.write(' 0x%x#1' % (tgt))
                out_f.write("\n")
            else:
                out_f.write("+IND+ ")
                out_f.write(hex(inst.addr))
                out_f.write(' 0xffffffffffffffff#1')
                out_f.write("\n")

    return

def get_exe_meta(binpath):
    cmd = "readelf -lW " + binpath
    p = subprocess.Popen(cmd, shell=True, stdout=subprocess.PIPE)
    out = p.communicate()[0]

    for line in out.split("\n"):
        line = line.strip()
        if line.startswith("LOAD") and "R E" in line:
            tokens = line.split()
            start = int(tokens[2], 16)
            size = int(tokens[4], 16)

            return (start, start+size-1)

    return (None, None)

def main():
    if len(sys.argv) != 5:
        usage()

    # set the recursion limit for deep searching
    sys.setrecursionlimit(10240)
    
    # read trace
    global OBJ_FILE
    global EXE_START
    global EXE_END
    global HEURISTIC_LEVEL
    HEURISTIC_LEVEL = int(sys.argv[4])
    print "reading trace and constructing cfg..."
    OBJ_FILE = read_trace(sys.argv[2])
    """
    for func in OBJ_FILE.funcs:
        print "Not Executed Function:", func.name
    """
    (EXE_START, EXE_END) = get_exe_meta(OBJ_FILE.path)
    print "EXE: ", hex(EXE_START), hex(EXE_END)
    
    # infer paths from conditional branches
    print "inferring paths from conditional branches..."
    infer_paths_from_cnd_branch()

    # infer paths from indirect calls
    print "inferring paths from indirect calls..."
    infer_paths_from_ind_call()

    print "generating extended log..."
    generate_extended_trace(ALL_PATHS)

if __name__ == "__main__":
    main()
