#!/usr/bin/python
import subprocess, os, struct, sys

class Instruction:

    def __init__(self, line=None):
        if line == None:
            self.addr = 0
            self.opcode = "lock"
            self.second_opcode = None
            self.length = 1
            self.op_str = ""
        else:
            tokens = line.split()
        
            self.addr = int(tokens[0], 16)
            self.opcode = tokens[1]
            self.second_opcode = None
            if self.opcode == "lock" or self.opcode.startswith("rep"):
                if tokens[2].strip() == "1":
                    self.length = 1
                else:
                    self.second_opcode = tokens[2]
                    self.length = int(tokens[3], 10)
            else:
                self.length = int(tokens[2], 10)
        
            # for control-flow instruction, op_str is appended after "||"
            self.op_str = ""
            if "||" in line:
                self.op_str = line.split("||")[-1]

        self.fall_through = 0
        # control-flow targets
        self.taken = 0
        self.non_taken = 0
        self.target = 0
        self.ind_targets = []
        self.is_cond_jmp = False
        self.is_direct_jmp = False
        self.is_indirect_jmp = False
        self.is_direct_call = False
        self.is_indirect_call = False
        self.is_ret = False
        self.is_syscall = False
    
        if self.opcode.startswith("j") and (not self.opcode.startswith("jmp")):
            self.is_cond_jmp = True
            self.taken = int(self.op_str, 16)
            self.non_taken = self.addr + self.length

        elif self.opcode.startswith("jmp"):
            tgt_addr = 0
            try:
                tgt_addr = int(self.op_str, 16)
            except:
                tgt_addr = 0

            if tgt_addr != 0:
                self.is_direct_jmp = True
                self.target = tgt_addr
                self.fall_through = tgt_addr
            else:
                self.is_indirect_jmp = True

        elif self.opcode.startswith("call"):
            tgt_addr = 0
            try:
                tgt_addr = int(self.op_str, 16)
            except:
                tgt_addr = 0

            if tgt_addr != 0:
                self.is_direct_call = True
                self.target = tgt_addr
            else:
                self.is_indirect_call = True

            self.fall_through = self.addr + self.length

        elif self.opcode.startswith("ret") or self.op_str.startswith("ret "):
            self.is_ret = True

        elif self.opcode == "syscall":
            self.is_syscall = True
            self.fall_through = self.addr + self.length
        else:
            self.fall_through = self.addr + self.length

    def add_indirect_target(self, tgt):
        if tgt not in self.ind_targets:
            self.ind_targets.append(tgt)
    
    def print_it(self):
        print hex(self.addr), self.opcode


class BasicBlock:
    def __init__(self, start_addr, end_addr, end_inst, func):
        self.start_addr = start_addr
        # for some basic blocks, when first building them, the first address is
        # not the effective address, would be fixed at `connect_bbs`
        self.end_addr = end_addr
        self.end_inst = end_inst
        self.func = func

        self.effective_start_addr = 0
        self.effective_start_inst = None
        self.succ_bbs = []
        # whether this bb is executed according to the trace
        self.is_executed = False
        # whether this block is included
        self.is_included = False
        self.is_on_blacklist = False

    def add_succ_bb(self, bb):
        if self.end_inst.is_cond_jmp:
            self.succ_bbs.append(bb)
        else:
            if bb not in self.succ_bbs:
                self.succ_bbs.append(bb)
    
    def set_effective_addr(self, addr):
        self.effective_start_addr = addr
        if addr not in self.func.inst_map:
            # for some black_hole function, may have instructions whose targets are not
            # right instruction addresses
            return False
        self.effective_start_inst = self.func.inst_map[addr]
        return True

class Function:
    def __init__(self, name, func_start, func_end, binFile):
        self.name = name
        self.func_start = func_start
        self.func_end = func_end
        self.binFile = binFile
        self.insts = []
        self.inst_map = {}
        self.inst_end_map = {}
        self.blocks = {}
        self.block_list = []
        self.callees = []
        self.is_plt = False
        self.is_executed = False

    def init(self, lines, start_index):
        i = start_index
        line = lines[i]
        
        while line[0:2] != "F:":
            inst = Instruction(line=line)

            if inst.opcode == "lock" and inst.second_opcode != None:
                # create a lock instruction
                lock_inst = Instruction(line=None)
                lock_inst.addr = inst.addr
                lock_inst.fall_through = inst.addr + 1
                # fix the instruction after lock
                inst.opcode = inst.second_opcode
                inst.addr = inst.addr + 1
                inst.length = inst.length - 1
                # add the lock instruction
                self.insts.append(lock_inst)
                self.inst_map[lock_inst.addr] = lock_inst
                self.inst_end_map[lock_inst.addr] = lock_inst
                
            
            self.insts.append(inst)
            self.inst_map[inst.addr] = inst
            self.inst_end_map[inst.addr + inst.length - 1] = inst
            i += 1
            if i == len(lines):
                break
            line = lines[i]
        
        # for the last instruction, set its fall_through to 0
        self.insts[-1].fall_through = 0
        
        return i
    
    def init_blocks(self):
        bb_starts = []
        bb_starts.append(self.insts[0].addr)

        for inst in self.insts:
            if inst.is_ret or  inst.is_syscall or inst.is_cond_jmp or \
                    inst.is_direct_call or inst.is_direct_jmp or \
                    inst.is_indirect_call or inst.is_indirect_jmp:
                next_inst_addr = inst.addr + inst.length
                if next_inst_addr not in self.inst_map:
                    next_inst_addr = self.get_first_inst_addr_after(next_inst_addr)
                if next_inst_addr != None and next_inst_addr <= self.func_end:
                    bb_starts.append(next_inst_addr)

            if inst.is_cond_jmp:
                if inst.taken >= self.func_start and inst.taken <= self.func_end:
                    bb_starts.append(inst.taken)

                if inst.non_taken >= self.func_start and inst.non_taken <= self.func_end:
                    bb_starts.append(inst.non_taken)

            if inst.is_direct_jmp:
                if inst.target >= self.func_start and inst.target <= self.func_end:
                    bb_starts.append(inst.target)

            if inst.is_indirect_jmp or inst.is_indirect_call:
                for tgt in inst.ind_targets:
                    if tgt >= self.func_start and tgt <= self.func_end:
                        bb_starts.append(tgt)

        # unique and sort all bb starts 
        bb_starts = list(set(bb_starts))
        bb_starts.sort()
        pre_bb_start = 0

        tmp_bb_ends = []
        
        for bb_start in bb_starts:
            if pre_bb_start != 0:
                end_addr = bb_start - 1
                tmp_end_inst = self.get_inst_endswith(end_addr)
                tmp_start_inst = None
                try:
                    tmp_start_inst = self.inst_map[pre_bb_start]
                except:
                    tmp_start_inst = None

                if tmp_end_inst and tmp_start_inst:
                    self.blocks[pre_bb_start] = BasicBlock(pre_bb_start, end_addr, tmp_end_inst, self)
                    # record bb end
                    tmp_bb_ends.append(end_addr)

            pre_bb_start = bb_start
        
        if pre_bb_start != 0:
            end_addr = self.insts[-1].addr + self.insts[-1].length - 1
            if end_addr not in tmp_bb_ends:
                tmp_start_inst = None
                try:
                    tmp_start_inst = self.inst_map[pre_bb_start]
                except:
                    tmp_start_inst = None

                if tmp_start_inst:
                    self.blocks[pre_bb_start] = BasicBlock(pre_bb_start, end_addr, self.insts[-1], self)
                    # record bb end
                    tmp_bb_ends.append(end_addr)
            pre_bb_start = 0
        
        # initialize the block_list
        block_starts = self.blocks.keys()
        block_starts.sort()
        for block_start in block_starts:
            self.block_list.append(self.blocks[block_start])

    def connect_bbs(self):
        for bb_start in self.blocks:
            bb = self.blocks[bb_start]

            end_inst = bb.end_inst

            if end_inst.is_cond_jmp:
                taken_bb = None
                non_taken_bb = None

                if end_inst.taken in self.blocks:
                    taken_bb = self.blocks[end_inst.taken]
                else:
                    # jump to another function
                    func = self.binFile.find_func_with_inst_addr(end_inst.taken)
                    if func:
                        if end_inst.taken not in func.blocks:
                            # for black-hole function, the start address maybe wrong, i.e., libc.so 0x2c389-->0x2c3a8
                            taken_bb = func.find_block_contains(end_inst.taken)
                            if taken_bb:
                                if not taken_bb.set_effective_addr(end_inst.taken):
                                    taken_bb = None
                        else:
                            taken_bb = func.blocks[end_inst.taken]

                if end_inst.non_taken in self.blocks:
                    non_taken_bb = self.blocks[end_inst.non_taken]
                else:
                    # somehow, idapro would end a function at conditional branch,
                    # for example, libc: 0x4a8bf 0x4a8c1
                    func = self.binFile.find_func_with_inst_addr(end_inst.non_taken)
                    if func and (end_inst.non_taken in func.blocks):
                        #libxul 0xd000c2
                        #print hex(end_inst.addr), hex(end_inst.non_taken), func.name
                        non_taken_bb = func.blocks[end_inst.non_taken]
                    else:
                        non_taken_bb = func.find_block_contains(end_inst.non_taken)
                        if non_taken_bb:
                            if not non_taken_bb.set_effective_addr(end_inst.non_taken):
                                non_taken_bb = None
                
                if taken_bb:
                    bb.add_succ_bb(taken_bb)
                
                if non_taken_bb:
                    bb.add_succ_bb(non_taken_bb)
            
            elif end_inst.is_direct_jmp or end_inst.is_direct_call:
                target_bb = None
                func = self.binFile.find_func_with_inst_addr(end_inst.target)

                if func:
                    if end_inst.target not in func.blocks:
                        # jmp to a function, but the start address of the function maybe wrong, 
                        # i.e., libc.so 0x3a4dc-->0x3a230
                        target_bb = func.find_block_contains(end_inst.target)
                        if target_bb:
                            if not target_bb.set_effective_addr(end_inst.target):
                                target_bb = None
                    else:
                        target_bb = func.blocks[end_inst.target]

                if target_bb:
                    bb.add_succ_bb(target_bb)

                if end_inst.is_direct_call and end_inst.fall_through > 0:
                    if end_inst.fall_through in self.blocks:
                        # following the call instruction is data, i.e., libc 0x211b2
                        next_bb = self.blocks[end_inst.fall_through]
                        bb.add_succ_bb(next_bb)

            elif end_inst.is_indirect_jmp or end_inst.is_indirect_call:
                for tgt in end_inst.ind_targets:
                    func = self.binFile.find_func_with_inst_addr(tgt)
                    target_bb = None

                    if func:
                        if tgt not in func.blocks:
                            # the indiret target maybe in the middle of a basic block
                            target_bb = func.find_block_contains(tgt)
                            if target_bb:
                                if not target_bb.set_effective_addr(tgt):
                                    target_bb = None
                        else:
                            target_bb = func.blocks[tgt]
                    
                    if target_bb:
                        bb.add_succ_bb(target_bb)
                    
                if end_inst.is_indirect_call and end_inst.fall_through > 0:
                    if end_inst.fall_through in self.blocks:
                        next_bb = self.blocks[end_inst.fall_through]
                        bb.add_succ_bb(next_bb)

            elif end_inst.is_syscall:
                if end_inst.fall_through in self.blocks:
                    # syscall is the last instruction of the function
                    next_bb = self.blocks[end_inst.fall_through]
                    bb.add_succ_bb(next_bb)

            elif end_inst.is_ret:
                pass
            
            else:
                if end_inst.fall_through != 0:
                    next_bb = None
                    if end_inst.fall_through not in self.blocks:
                        next_bb = None
                        """
                        next_bb = self.find_block_contains(end_inst.fall_through)
                        # for example, libc: 0xefb8b 0xefb8d 0xefb83 0xefb8f
                        if end_inst.fall_through not in self.inst_map:
                            next_bb = None
                        else:
                            next_bb.set_effective_addr(end_inst.fall_through)
                        """
                    else:
                        next_bb = self.blocks[end_inst.fall_through]
                    
                    if next_bb != None:
                        bb.add_succ_bb(next_bb)
    
    # whether e appears more than twice in l
    def number_of(self, l, e):
        n = 0
        for i in range(0, len(l)):
            if l[i] == e:
                n += 1
        return n

    
    #Currently, only find paths without loops and limit the path number
    #TODO: Identify Loops
    def find_paths(self, start_block, cur_path):
        if len(self.paths) > 2048:
            return

        if len(start_block.succ_bbs) == 0:
            self.paths.append(cur_path)
            return
        
        for succ_block in start_block.succ_bbs:
            # the succ block is within current function
            if self.in_func(succ_block.start_addr):
                if succ_block not in cur_path:
                #if self.number_of(cur_path, succ_block) < 2:

                    new_path = cur_path[:]
                    new_path.append(succ_block)
                    self.find_paths(succ_block, new_path)
        return

    def build_call_graph(self):
        for block_addr in self.blocks:
            block = self.blocks[block_addr]

            for succ_block in block.succ_bbs:
                if not self.in_func(succ_block.start_addr):
                    target_func = self.binFile.find_func_with_inst_addr(succ_block.start_addr)

                    if target_func and (target_func not in self.callees):
                        self.callees.append(target_func)


    def find_block_contains(self, addr):
        l = 0
        h = len(self.block_list) - 1

        while l < h:
            m = (l + h) / 2
            bb = self.block_list[m]

            if addr < bb.start_addr:
                h = m - 1
            elif addr > bb.end_addr:
                l = m + 1
            else:
                return bb

        if l == h:
            bb = self.block_list[l]
            if bb.start_addr <= addr and addr <= bb.end_addr:
                return bb
        
        """
        print hex(addr), hex(self.func_start), hex(self.func_end)
        for i in range(0, len(self.block_list)):
            b = self.block_list[i]
            print hex(b.start_addr), hex(b.end_addr)

        assert False
        """
        return None


    def in_func(self, inst_addr):
        if inst_addr >= self.func_start and inst_addr <= self.func_end:
            return True

        return False

    def get_inst_addr(self, inst_addr):
        if inst_addr in self.inst_map:
            return inst_addr
        
        for addr in self.inst_map:
            if inst_addr >= addr and inst_addr <= (addr + self.inst_map[addr].length):
                return addr

        return None

    def get_first_inst_addr_after(self, addr):
        for inst in self.insts:
            if inst.addr > addr:
                return inst.addr
        
        return None

    def get_inst_endswith(self, end_addr):
        # libxul has a big problem for this function: 0x45a8127 jumps to nowhere
        ret = None
        try:
            ret = self.inst_end_map[end_addr]
        except:
            ret = None

        if ret != None:
            return ret

        for i in range(0, len(self.insts)):
            inst = self.insts[i]
            if inst.addr > end_addr:
                return self.insts[i-1]

        return None

        """
        
        l = 0
        h = len(self.insts) - 1
        while l < h:
            m = (l + h) / 2
            inst = self.insts[m]
            next_inst = self.insts[m+1]

            if inst.addr + inst.length - 1 < end_addr and end_addr < next_inst.addr:
                return self.insts[m]
            elif end_addr < inst.addr:
                h = m - 1
            elif end_addr > next_inst.addr:
                l = m + 1
            else:
                return None

        if l == h:

            if l - 1 < 0:
                return None

            if l + 1 >= len(self.insts):
                return None

            pre_inst = self.insts[l-1]
            inst = self.insts[l]
            next_inst = self.insts[l+1]

            if pre_inst.addr + pre_inst.length - 1 < end_addr and end_addr < inst.addr:
                return self.insts[(l-1)]
            elif inst.addr + inst.length - 1 < end_addr and end_addr < next_inst.addr:
                return self.insts[l]
            else:
                #print hex(end_addr), l, h, hex(pre_inst.addr), hex(inst.addr), hex(next_inst.addr)
                return None
        else:
            return None
        """

    def print_it(self):
        print hex(self.func_start), self.name
        for inst in self.insts:
            inst.print_it()

class BinFile:
    def __init__(self, path, asm_file):
        self.path = path
        self.name = path.split("/")[-1]

        self.text_mem_addr = 0
        self.text_file_off = 0
        self.text_size = 0
        # init meta data related to .text section
        cmd = "readelf -SW " + path
        p = subprocess.Popen(cmd, shell=True, stdout=subprocess.PIPE)
        out = p.communicate()[0]
        lines = out.split('\n')
        for i in range(0, len(lines)):
            line = lines[i]
            line = line.strip()
            tokens = line.split()
            if len(tokens) < 2:
                continue
            if tokens[1] == ".text":
                self.text_mem_addr = int("0x"+tokens[3].strip(), 16)
                self.text_file_off = int("0x"+tokens[4].strip(), 16)
                self.text_size = int("0x"+tokens[5], 16)


        self.funcs = []
        self.func_starts = []
        # all .plt entries
        self.plt_entries = {}
        
        # read cfg file to init self.funcs, self.func_starts, self.plt_entries 
        self.read_cfg(asm_file)

        # indirect call/jump address to jump table base address
        self.indcall_2_jump_tables = {}
        # indirect call/jump address to offset table base address
        self.indcall_2_offset_tables = {}
        # the jump table contents{base_addr: [code_pointer_1, code_pointer_2, ...]}
        self.jump_tables = {}
        # the offset table contents{base_addr: [code_pointer_1, code_pointer_2, ...]}
        self.offset_tables = {}
        
        print "identifying jump tables..."
        # identify the jump tables and offset tables
        self.identify_jump_tables()

        print "fixing jmp table targets..."
        # fix indirect call/jump targets
        self.fix_jmp_table_tgts()

        # initialize each function's blocks, should be done
        # after fixing jump table targets
        print "initializing blocks"
        for func in self.funcs:
            func.init_blocks()
        
        print "connecting bbs..."
        self.connect_func_bbs()
        print "cfg is ready!"
        
        print "building call graph..."
        self.build_call_graph()

        print "BinFile has been initialized!"
        
        """
        print "finding all paths in each function..."
        for func in self.funcs:
            func.build_paths()
        """

    def build_call_graph(self):
        for func in self.funcs:
            func.build_call_graph()
        return

    def connect_func_bbs(self):
        for func in self.funcs:
            func.connect_bbs()

    def read_cfg(self, asm_file):

        with open(asm_file, 'r') as cfg_file:
            lines = cfg_file.readlines()
            line_num = len(lines)
            i = 0
            while i < line_num:
                line = lines[i]

                if line[0:2] == "F:":
                    tokens = line.split()
                    func_name = tokens[1]
                    func_start = int(tokens[2], 16)
                    func_end = int(tokens[3], 16)
                    is_plt = False
                    if tokens[4].strip() == "True":
                        is_plt = True

                    func = Function(func_name, func_start, func_end, self)
                    i = func.init(lines, i+1)
                    self.funcs.append(func)
                    self.func_starts.append(func_start)
                    if is_plt:
                        self.plt_entries[func_start] = func_name
                        func.is_plt = True
                else:
                    assert False


    def is_legal_inst(self, addr):
        h = len(self.funcs) - 1
        l = 0

        while l < h:
            mid = (l+h)/2
            func = self.funcs[mid]

            if addr < func.func_start:
                h = mid - 1
            elif addr > func.func_end:
                l = mid + 1
            else:
                if addr in func.inst_map:
                    return True
                else:
                    return False

        if l == h:
            func = self.funcs[l]
            if addr >= func.func_start and addr <= func.func_end:
                if addr in func.inst_map:
                    return True
                else:
                    return False
            else:
                return False

        return False

    def identify_jump_tables(self):
        # jmpq   *0x4ec4c0(,%rdx,8)
        for func in self.funcs:
            for inst in func.insts:
                opcode = inst.opcode
                op_str = inst.op_str
                if opcode.startswith("jmp"):
                    if ("[" in op_str) and ("]" in op_str):
                        operand = op_str.split("[")[1].split("]")[0]
                        if ("*8" in operand) and ("+" in operand):
                            table_base_addr = 0
                            try:
                                table_base_addr = int(operand.split("+")[1].strip(), 16)
                            except:
                                try:
                                    table_base_addr = int(operand.split("+")[0].strip(), 16)
                                except:
                                    table_base_addr = 0

                            if table_base_addr > 0:
                                self.indcall_2_jump_tables[inst]  = table_base_addr

                                if table_base_addr not in self.jump_tables:
                                    self.jump_tables[table_base_addr] = []

        
        print "There are ", len(self.jump_tables), " jump tables"
        # read the jump_table contents
        fd = os.open(self.path, os.O_RDONLY)
        for base_addr in self.jump_tables:
            file_addr = base_addr - (self.text_mem_addr - self.text_file_off)
            os.lseek(fd, file_addr, os.SEEK_SET)
            entry_value = struct.unpack("Q", os.read(fd, 8))[0]

            while (entry_value >= self.text_mem_addr and 
                    entry_value <= self.text_mem_addr + self.text_size) and self.is_legal_inst(entry_value):
                if entry_value not in self.jump_tables[base_addr]:
                    self.jump_tables[base_addr].append(entry_value)
                file_addr += 8
                os.lseek(fd, file_addr, os.SEEK_SET)
                entry_value = struct.unpack("Q", os.read(fd, 8))[0]
        os.close(fd)

        """
        lea    LABEL(unaligned_table)(%rip), %r10
        movslq    (%r10, %r9,4), %r9
        pcmpeqb    %xmm1, D(%xmm0)        /* Any null chars? */
        lea    (%r10, %r9), %r10
        jmp    *%r10            /* jump to corresponding case */

        or

        lea    0xfbe87(%rip),%r10        # 187a98 <_itoa_lower_digits@@GLIBC_PRIVATE+0x1c18>
        movslq (%r10,%r9,4),%r9
        lea    (%r10,%r9,1),%r10
        jmpq   *%r10
        """
        # TODO: fine grained analysis
        for func in self.funcs:
            inst_num = len(func.insts)
            for i in range(0, inst_num):
                inst = func.insts[i]
                opcode = inst.opcode
                
                if not opcode == "lea":
                    continue

                op_str = inst.op_str
                operands = op_str.split()

                offset_table_base_addr = 0
                if ("[rip +" in op_str):
                    try:
                        offset = int(op_str.split("[rip +")[1].split("]")[0].strip(), 16)
                        offset_table_base_addr = inst.addr + inst.length + offset
                    except:
                        offset_table_base_addr = 0
                if ("[rip -" in op_str):
                    try:
                        offset = int(op_str.split("[rip -")[1].split("]")[0].strip(), 16)
                        offset_table_base_addr = inst.addr + inst.length - offset
                    except:
                        offset_table_base_addr = 0
                
                j = 0
                if offset_table_base_addr > 0 and (i + 3 < inst_num):
                    jmp_inst = func.insts[i+3]
                    j = i + 3

                    if not jmp_inst.is_indirect_jmp and (i + 4 < inst_num):
                        jmp_inst = func.insts[i+4]
                        j = i + 4

                    if jmp_inst.is_indirect_jmp:
                        pattern_found = False
                        for idx in range(i+1, j):
                            tmp_inst = func.insts[idx]
                            if tmp_inst.opcode == "lea" and jmp_inst.op_str.strip() in tmp_inst.op_str:
                                pattern_found = True
                                break
                        
                        if pattern_found:
                            self.indcall_2_offset_tables[jmp_inst] = offset_table_base_addr

                            if offset_table_base_addr not in self.offset_tables:
                                self.offset_tables[offset_table_base_addr] = []

        
        print "There are ", len(self.offset_tables), "offset tables"
        # read the offset table contents
        fd = os.open(self.path, os.O_RDONLY)
        for base_addr in self.offset_tables:
            file_addr = base_addr - (self.text_mem_addr - self.text_file_off)
            os.lseek(fd, file_addr, os.SEEK_SET)
        
            entry_value = 0
            try:
                entry_value = struct.unpack("i", os.read(fd, 4))[0]
            except:
                entry_value = 0

            if entry_value == 0:
                continue
            
            code_addr = entry_value + base_addr
            while (code_addr >= self.text_mem_addr and code_addr <= self.text_mem_addr + self.text_size) and self.is_legal_inst(code_addr):
                if code_addr not in self.offset_tables[base_addr]:
                    self.offset_tables[base_addr].append(code_addr)
                file_addr += 4
                os.lseek(fd, file_addr, os.SEEK_SET)
                try:
                    entry_value = struct.unpack("i", os.read(fd, 4))[0]
                except:
                    entry_value = 0

                if entry_value == 0:
                    break

                code_addr = entry_value + base_addr
        os.close(fd)


    def fix_jmp_table_tgts(self):
        # fix the indirect targets
        for inst in self.indcall_2_jump_tables:
            base_addr = self.indcall_2_jump_tables[inst]
            tgts = self.jump_tables[base_addr]

            for tgt in tgts:
                inst.add_indirect_target(tgt)
        
        for inst in self.indcall_2_offset_tables:
            base_addr = self.indcall_2_offset_tables[inst]
            tgts = self.offset_tables[base_addr]

            for tgt in tgts:
                inst.add_indirect_target(tgt)

    def find_func_with_inst_addr(self, inst_addr):
        h = len(self.funcs) - 1
        l = 0

        while l < h:
            mid = (l+h)/2
            func = self.funcs[mid]

            if inst_addr < func.func_start:
                h = mid - 1
            elif inst_addr > func.func_end:
                l = mid + 1
            else:
                return func

        if l == h:
            func = self.funcs[l]
            if inst_addr >= func.func_start and inst_addr <= func.func_end:
                return func
            else:
                # for some instructions in black_hole*, they call wrong addresses
                """
                print hex(inst_addr), hex(func.func_start), hex(func.func_end), func.name
                assert False
                """
                return None

        # for some instructions in black_hole*, they call wrong addresses
        """
        print hex(inst_addr)
        assert False
        """
        return None

    def print_it(self):
        print "name:", self.name
        print "text_mem_addr:", hex(self.text_mem_addr)
        print "text_file_offset:", hex(self.text_file_off)
        print "text_size:", hex(self.text_size)
        for func in self.funcs:
            func.print_it()

