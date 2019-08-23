from struct import *

import sys
sys.dont_write_bytecode = True

class ARCH(object):
    INT_SIZE        = 8

# ELF Header
class EHDR(object):
    # size of fields in ELF header
    e_ident_size        = 16
    e_type_size         = 2
    e_machine_size      = 2
    e_version_size      = 4
    e_entry_size        = ARCH.INT_SIZE
    e_phoff_size        = ARCH.INT_SIZE
    e_shoff_size        = ARCH.INT_SIZE
    e_flags_size        = 4
    e_ehsize_size       = 2
    e_phentsize_size    = 2
    e_phnum_size        = 2
    e_shentsize_size    = 2
    e_shnum_size        = 2
    e_shstrndx_size     = 2

    # offset of fields in ELF header
    e_ident_offset        = 0
    e_type_offset         = e_ident_offset + e_ident_size
    e_machine_offset      = e_type_offset + e_type_size
    e_version_offset      = e_machine_offset + e_machine_size
    e_entry_offset        = e_version_offset + e_version_size
    e_phoff_offset        = e_entry_offset + e_entry_size
    e_shoff_offset        = e_phoff_offset + e_phoff_size
    e_flags_offset        = e_shoff_offset + e_shoff_size
    e_ehsize_offset       = e_flags_offset + e_flags_size
    e_phentsize_offset    = e_ehsize_offset + e_ehsize_size
    e_phnum_offset        = e_phentsize_offset + e_phentsize_size
    e_shentsize_offset    = e_phnum_offset + e_phnum_size
    e_shnum_offset        = e_shentsize_offset + e_shentsize_size
    e_shstrndx_offset     = e_shnum_offset + e_shnum_size

    # mapping from offset of size
    offset2size = {
        e_ident_offset      : e_ident_size,
        e_type_offset       : e_type_size,
        e_machine_offset    : e_machine_size,
        e_version_offset    : e_version_size,
        e_entry_offset      : e_entry_size,
        e_phoff_offset      : e_phoff_size,
        e_flags_offset      : e_flags_size,
        e_ehsize_offset     : e_ehsize_size,
        e_phentsize_offset  : e_phentsize_size,
        e_phnum_offset      : e_phnum_size,
        e_shentsize_offset  : e_shentsize_size,
        e_shnum_offset      : e_shnum_size,
        e_shstrndx_offset   : e_shstrndx_size,
    }

# program header
class PHDR(object):
    PT_NULL         = 0
    PT_LOAD         = 1
    PT_DYNAMIC      = 2
    PT_INTERP       = 3
    PT_NOTE         = 4
    PT_SHLIB        = 5
    PT_PHDR         = 6
    PT_TLS          = 7
    PT_NUM          = 8
    PT_LOOS         = 0x60000000
    PT_GNU_EH_FRAME = 0x6474e550
    PT_GNU_STACK    = 0x6474e551
    PT_GNU_RELRO    = 0x6474e552
    PT_LOSUNW       = 0x6ffffffa
    PT_SUNWBSS      = 0x6ffffffa
    PT_SUNWSTACK    = 0x6ffffffb
    PT_HISUNW       = 0x6fffffff
    PT_HIOS         = 0x6fffffff
    PT_LOPROC       = 0x70000000
    PT_HIPROC       = 0x7fffffff

    # size of fields in a PHDR entry
    p_type_size     = 4
    p_flags_size    = 4
    p_offset_size   = ARCH.INT_SIZE
    p_vaddr_size    = ARCH.INT_SIZE
    p_paddr_size    = ARCH.INT_SIZE
    p_filesz_size   = ARCH.INT_SIZE
    p_memsz_size    = ARCH.INT_SIZE
    p_align_size    = ARCH.INT_SIZE

    # offset of fields in a PHDR entry
    p_type_offset   = 0
    p_offset_offset = p_type_offset + p_type_size + (0 if ARCH.INT_SIZE == 4 else p_flags_size)
    p_vaddr_offset  = p_offset_offset + p_offset_size
    p_paddr_offset  = p_vaddr_offset + p_vaddr_size
    p_filesz_offset = p_paddr_offset + p_paddr_size
    p_memsz_offset  = p_filesz_offset + p_filesz_size
    p_flags_offset  = (p_type_offset + p_type_size) if ARCH.INT_SIZE == 8 else (p_memsz_offset + p_memsz_size)
    p_align_offset  = p_memsz_offset + p_memsz_size + (p_flags_size if ARCH.INT_SIZE == 4 else 0)

    # mapping from offset to size
    offset2size = {
        p_type_offset   : p_type_size,
        p_flags_offset  : p_flags_size,
        p_offset_offset : p_offset_size,
        p_vaddr_offset  : p_vaddr_size,
        p_paddr_offset  : p_paddr_size,
        p_filesz_offset : p_filesz_size,
        p_memsz_offset  : p_memsz_size,
        p_align_offset  : p_align_size
    }

    # segment flags
    PF_X = 1
    PF_W = 2
    PF_R = 4
    PF_MASKOS   = 0x0ff00000
    PF_MASKPROC = 0xf0000000

# section header
class SHDR(object):
    # size of fields in a section header
    sh_name_size        = 4
    sh_type_size        = 4
    sh_flags_size       = ARCH.INT_SIZE
    sh_addr_size        = ARCH.INT_SIZE
    sh_offset_size      = ARCH.INT_SIZE
    sh_size_size        = ARCH.INT_SIZE
    sh_link_size        = 4
    sh_info_size        = 4
    sh_align_size       = ARCH.INT_SIZE
    sh_entsize_size     = ARCH.INT_SIZE

    # offset of fields in a section header
    sh_name_offset      = 0
    sh_type_offset      = sh_name_offset + sh_name_size
    sh_flags_offset     = sh_type_offset + sh_type_size
    sh_addr_offset      = sh_flags_offset + sh_flags_size
    sh_offset_offset    = sh_addr_offset + sh_addr_size
    sh_size_offset      = sh_offset_offset + sh_offset_size
    sh_link_offset      = sh_size_offset + sh_size_size
    sh_info_offset      = sh_link_offset + sh_link_size
    sh_align_offset     = sh_info_offset + sh_info_size
    sh_entsize_offset   = sh_align_offset + sh_align_size

    # mapping from offset to size    
    offset2size = {
        sh_name_offset      : sh_name_size,
        sh_type_offset      : sh_type_size,
        sh_flags_offset     : sh_flags_size,
        sh_addr_offset      : sh_addr_size,
        sh_offset_offset    : sh_offset_size,
        sh_size_offset      : sh_size_size,
        sh_link_offset      : sh_link_size,
        sh_info_offset      : sh_info_size,
        sh_align_offset     : sh_align_size,
        sh_entsize_offset   : sh_entsize_size
    }

#option in dynamic section
class DYNAMIC(object):
    DT_NULL=0
    DT_NEEDED=1
    DT_PLTRELSZ=2
    DT_PLTGOT=3
    DT_HASH=4
    DT_STRTAB=5
    DT_SYMTAB=6
    DT_RELA=7
    DT_RELASZ=8
    DT_RELAENT=9
    DT_STRSZ=10
    DT_SYMENT=11
    DT_INIT=12
    DT_FINI=13
    DT_SONAME=14
    DT_RPATH=15
    DT_SYMBOLIC=16
    DT_REL=17
    DT_RELSZ=18
    DT_RELENT=19
    DT_PLTREL=20
    DT_DEBUG=21
    DT_TEXTREL=22
    DT_JMPREL=23
    DT_BIND_NOW=24
    DT_INIT_ARRAY=25
    DT_FINI_ARRAY=26
    DT_INIT_ARRAYSZ=27
    DT_FINI_ARRAYSZ=28
    DT_RUNPATH=29
    DT_FLAGS=30
    DT_ENCODING=32
    DT_PREINIT_ARRAY=32
    DT_PREINIT_ARRAYSZ=33
    DT_NUM=34
    DT_LOOS=0x6000000d
    DT_VERSYM=0x6ffffff0
    DT_VERNEED=0x6ffffffe
    DT_VERNEEDNUM=0x6fffffff
    DT_HIOS=0x6ffff000
    DT_LOPROC=0x70000000
    DT_HIPROC=0x7fffffff

    # size of fields
    opt_size = ARCH.INT_SIZE
    value_size = ARCH.INT_SIZE

class SYMT(object):
    # bind
    STB_LOCAL   = 0
    STB_GLOBAL  = 1
    STB_WEAK    = 2
    STB_LOOS    = 10
    STB_HIOS    = 12
    STB_LOPROC  = 13
    STB_HIPROC  = 15

    # type
    STT_NOTYPE  = 0
    STT_OBJECT  = 1
    STT_FUNC    = 2
    STT_SECTION = 3
    STT_FILE    = 4
    STT_COMMON  = 5
    STT_TLS     = 6
    STT_LOOS    = 10
    STT_HIOS    = 12
    STT_LOPROC  = 13
    STT_SPARC_REGISTER = 13
    STT_HIPROC  = 15

    # Visibility

    # size of fields
    st_name_size    = 4
    st_value_size   = ARCH.INT_SIZE
    st_size_size    = ARCH.INT_SIZE
    st_info_size    = 1
    st_other_size   = 1
    st_shndx_size   = 2

    # offset of fields
    st_name_offset  = 0
    if ARCH.INT_SIZE == 4:
        st_value_offset = (st_name_offset + st_name_size)
        st_size_offset  = (st_value_offset + st_value_size)
        st_info_offset  = (st_size_offset + st_size_size)
        st_other_offset = (st_info_offset + st_info_size)
        st_shndx_offset = (st_other_offset + st_other_size)
    else:
        st_info_offset  = (st_name_offset + st_name_size)
        st_other_offset = (st_info_offset + st_info_size)
        st_shndx_offset = (st_other_offset + st_other_size)
        st_value_offset = (st_shndx_offset + st_shndx_size)
        st_size_offset  = (st_value_offset + st_value_size)

    # mapping from offset to size    
    offset2size = {
        st_name_offset  : st_name_size,
        st_value_offset : st_value_size,
        st_size_offset  : st_size_size,
        st_info_offset  : st_info_size,
        st_other_offset : st_other_size,
        st_shndx_offset : st_shndx_size,
        }

def ST_BIND(info):
    return ((info) >> 4)

def ST_TYPE(info):
    return ((info) & 0xf)

def ST_INFO(bind, type):
    return (((bind)<<4)+((type)&0xf))

def ST_VISIBILITY(other):
    return ((other)&0x3)

# the followings are about debug info extraction and overwriting
class DW_ENC(object):
    DW_EH_PE_absptr     = 0x00  # An absolute pointer
    DW_EH_PE_omit       = 0xff  # omitted
    DW_EH_PE_uleb128    = 0x01  # unsigned LEB128
    DW_EH_PE_udata2     = 0x02  # unsigned 2-bytes
    DW_EH_PE_udata4     = 0x03  # unisgned 4-bytes
    DW_EH_PE_udata8     = 0x04  # unsigned 8-bytes
    DW_EH_PE_signed     = 0x8   # signed number, sized depends on 32-bit or 64-bit
    DW_EH_PE_sleb128    = 0x9   # signed LEB128
    DW_EH_PE_sdata2     = 0xa   # signed 2-bytes
    DW_EH_PE_sdata4     = 0xb   # signed 4-bytes
    DW_EH_PE_sdata8     = 0xc   # signed 8-bytes

    DW_EH_PE_pcrel      = 0x10  # value is PC relative
    DW_EH_PE_textrel    = 0x20  # value is text relative
    DW_EH_PE_datarel    = 0x30  # value is data relative
    DW_EH_PE_funcrel    = 0x40  # value is relative to start of function
    DW_EH_PE_aligned    = 0x50  # value is aligned
    DW_EH_PE_indirect   = 0x80  # This is actually the address of the real value

# the format of .eh_frame_hdr section
class EH_FRAME_HDR(object):
    # size of fields
    version_size = 1
    eh_frame_ptr_enc_size = 1
    fde_count_enc_size = 1
    table_enc_size = 1

    def __init__(self):
        # fields
        self.version = None
        self.eh_frame_ptr_enc = None
        self.fde_count_enc = None
        self.table_enc = None
        self.eh_frame_ptr = None
        self.fde_count = None
        self.table = []
        self.fde_count_offset = None

        # defined by hong
        self.addr = None

    class entry(object):
        def __init__(self):
            self.fde_init_loc = None
            self.fde_data_offset = None

    # print it
    def printit(self):
        print ".eh_frame_hdr loaded @", hex(self.addr)
        print "version", self.version
        print "eh_frame_ptr encoding", hex(self.eh_frame_ptr_enc)
        print "fde_count encoding", hex(self.fde_count_enc)
        print "table_enc", hex(self.table_enc)
        print "eh_frame_ptr", hex(self.eh_frame_ptr)
        print "fde_count", hex(self.fde_count)
        for index in xrange(self.fde_count):
            print "\t", hex(self.table[index].fde_init_loc), \
                        hex(self.table[index].fde_data_offset)

# the leading structure in .eh_frame section
class CIE(object):
    length_size = 4
    cie_id_size = 4
    version_size = 1

    def __init__(self):
        # fields
        self.length = None
        self.cie_id = None
        self.version = None
        self.aug = None
        self.code_align_fac = None
        self.data_align_fac = None
        self.ret_addr_reg = None
        self.aug_data_len = None
        self.aug_data = None
        self.init_instrs = None

        # defined by hong
        self.foff_ef = None
        self.aug_data_foff = None
        self.lsda_encoding = None
        self.fde_encoding = None
        self.personality_encoding = None
        self.personality = None
        self.is_signal_frame = False

    def printit(self):
        print "CIE @ offset 0x%lx" % self.foff_ef
        print "\tLength:  0x%x" % self.length
        print "\tID:      0x%x" % self.cie_id
        print "\tVersion: 0x%x" % self.version
        print "\tAugment: \"%s\"" % self.aug[:-1]
        print "\tCode Align Fac: 0x%lx" % self.code_align_fac
        print "\tData Align Fac: 0x%lx" % self.data_align_fac
        print "\tRet addr reg:   0x%lx" % self.ret_addr_reg
        print "\tAug data len:   0x%lx" % self.aug_data_len
        print "\tAug data: ", 
        printPacked(self.aug_data)
        print "\tInit Instrcutions:", 
        printPacked(self.init_instrs)
        if self.personality != None:
            print "\tpersonality function:", hex(self.personality)

# the following structure in .eh_frame section
class FDE(object):
    length_size = 4
    fde_id_size = 4

    def __init__(self):
        # fields
        self.length = None
        self.cie_foff_id = None
        self.pc_begin = None
        self.pc_end = None
        self.aug_data_len = None
        self.aug_data = None
        self.cfi = None
        self.LSDA_pointer = None

        # defined by me
        self.foff_ef= None
        self.ldsa = None

    def printit(self):
        print "FDE @ offset 0x%lx" % self.foff_ef
        print "\tLength: 0x%lx" % self.length
        print "\tCIE offset: 0x%lx" % (self.foff_ef + FDE.length_size - self.cie_foff_id)
        print "\tPC start: %lx" % self.pc_begin
        print "\tPC end: %lx" % self.pc_end
        print "\tAug data len: 0x%lx" % self.aug_data_len
        print "\tAug data: ", 
        printPacked(self.aug_data)
        if self.LSDA_pointer != None:
            print "\t\tLSDA pointer: 0x%lx" % self.LSDA_pointer
            self.lsda.printit()
        print "\tInit Instrcutions:",
        printPacked(self.cfi)

# structures in .gcc_except_table section
class LSDA(object):
    # lsda header
    lpstart_encoding_size = 1
    # ttable: type table
    ttable_entry_encoding_size = 1
    # cstable: call-site table
    cstable_entry_encoding_size = 1

    acc_extra_bytes = 0

    def __init__(self):
        # the header
        self.lpstart_encoding = None
        self.LPStart = 0
        self.ttable_entry_encoding = None
        self.ttable_foff_to = -1 # from the end of the header

        # cs table header
        self.cstable_entry_encoding = None
        self.cstable_size = None

        self.cstable = []
        self.ttable_neg = []
        self.ttable_pos = []
        # atable means action table
        self.atable = []

        # defined by hong
        self.func_begin = None
        self.ttable_foff = None
        self.ttable_max_index = None
        self.ttable_min_offset = None

        self.extra_bytes = 0
        self.new_ttable_foff_to = -1
        self.new_cstable_size = None
        self.new_cstable = []

    def printit(self):
        print ""
        print "\t\tPrinting LSDA"
        print "\t\textra_bytes", self.extra_bytes
        print "\t\tlpstart encoding:", hex(self.lpstart_encoding)
        print "\t\tLPStart:", hex(self.LPStart)
        print "\t\ttype table entry encoding", hex(self.ttable_entry_encoding)
        print "\t\ttype table offset", hex(self.ttable_foff_to)
        print "\t\tcall site table encodig", hex(self.cstable_entry_encoding)
        print "\t\tcall site table size", hex(self.cstable_size)
        for cs_entry in self.cstable:
            cs_entry.printit(self.func_begin, self.LPStart)

        if len(self.atable) != 0:
            print "\t\taction table:"
            for a_entry in self.atable:
                a_entry.printit()
        else:
            print "\t\tno action table"

        if self.ttable_foff_to == -1:
            print "\t\tno type table"
        else:
            print "\t\ttype table"
            for index in xrange(0, len(self.ttable_neg)):
                print "\t\t\ttypeinfo", self.ttable_neg[index][0], hex(self.ttable_neg[index][1])

            for index in xrange(0, len(self.ttable_pos)):
                print "\t\t\t",
                for inner_index in xrange(0, len(self.ttable_pos[index])):
                    print self.ttable_pos[index][inner_index]

    class cstable_entry(object):
        def __init__(self):
            self.cs_start = None
            self.cs_len = None
            self.cs_lp = None
            self.cs_action = None

        def printit(self, func_begin=0, lpstart=0):
            print "\t\t\tcs_start ", hex(self.cs_start + func_begin)
            print "\t\t\tcs_len   ", hex(self.cs_len)
            print "\t\t\tcs_lp    ", hex(self.cs_lp + lpstart)
            print "\t\t\tcs_action ", hex(self.cs_action)

    class atable_entry(object):
        def __init__(self):
            self.ar_filter = None
            self.ar_disp = None

        def printit(self):
            print "\t\t\tar_filter ", hex(self.ar_filter)
            print "\t\t\tar_disp   ", hex(self.ar_disp)

def printPacked(packed):
    for i in xrange(0, len(packed)):
        print "%02x" % (unpack("<B", packed[i])[0]),
    print ""

def pfmt(size):
    if size == 4:
        return "<i"
    elif size == 8:
        return "<q"
    elif size == 2:
        return "<h"
    elif size == 1:
        return "<b"
    else:
        print "unsupported size in pack_fmt %d" % size
        exit(1)
