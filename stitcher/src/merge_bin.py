#!/usr/bin/env python

import os
import sys
import argparse
import subprocess
from elf_basic import *

sys.dont_write_bytecode = True

eb = None
mytext_base = 0

def get_new_segment_base_addr(bin_name):
    max_mem_addr = 0
    elf_type_str = eb.get_elfhdr_info(bin_name, "Type:")
    if elf_type_str == 'EXEC':
        seg_infos = eb.get_segment_info(bin_name, "*")
        for seg_info in seg_infos:
            mem_addr_end = int(seg_info["vaddr"], 16) + int(seg_info["memsz"], 16)
            print hex(int(seg_info["vaddr"], 16)), hex(mem_addr_end)
            if mem_addr_end > max_mem_addr:
                max_mem_addr = mem_addr_end
        return (max_mem_addr / 0x100000 + 1) * 0x100000
    elif elf_type_str == 'DYN':
        print "does not support library yet"
        exit(1)
    else:
        print "unsupport ELF type", elf_type_str
        exit(1)

#relocate the .interp section to the end of data segment
def relocate_interp(binname):
    # this method is also obselete, as I find some problems compiled with clang does
    # not have enough NOTE sections for us to shift interp

    # OK, I guess the goal here is to create space to insert another PHDR header 
    # as after INTERP is the NOTE section, which is not used by the program,
    # so this function is to move INTERP section into NOTE, and use the orginal INTERP
    # space for the new PHDR header.

    global eb
    interp_mem_addr = eb.get_section_info(binname,".interp", "addr")

    if(interp_mem_addr == None):
        return None;

    interp_offset = eb.get_section_info(binname,".interp", "offset")
    interp_size = eb.get_section_info(binname,".interp", "size")

    print "interp offset : %x" % interp_offset
    print "interp size   : %x" % interp_size

    #now get the PHDR information
    phdr_num = eb.get_elfhdr_info(binname, "Number of program headers:");
    phdr_size = eb.get_elfhdr_info(binname,"Size of program headers:");
    phdr_start = eb.get_elfhdr_info(binname,"Start of program headers:");

    #relocate interp to the new place
    fd = os.open(binname, os.O_RDWR);
    os.lseek(fd, interp_offset, os.SEEK_SET)
    buf = os.read(fd, interp_size);
    new_interp_offset = interp_offset + phdr_size  # FIXME <-- what is this ?
    os.lseek(fd, new_interp_offset, os.SEEK_SET)
    os.write(fd, buf);
    os.close(fd);

    #get phdr header info of interpreter
    interp_vaddr = eb.get_phdr_info(binname, PHDR.PT_INTERP, PHDR.p_vaddr_offset);
    interp_paddr = eb.get_phdr_info(binname, PHDR.PT_INTERP, PHDR.p_paddr_offset);
    print "interpreter vaddr : %lx" % interp_vaddr
    print "interpreter paddr : %lx" % interp_paddr
    new_interp_vaddr = (interp_vaddr & (~0xfff)) | (new_interp_offset & 0xfff)
    new_interp_paddr = (interp_paddr & (~0xfff)) | (new_interp_offset & 0xfff)
    print "new interpreter vaddr : %lx" % new_interp_vaddr
    print "new interpreter paddr : %lx" % new_interp_paddr

    #modify the interp offset
    fd = os.open(binname, os.O_RDWR);
    os.lseek(fd, phdr_start, os.SEEK_SET)
    for size in xrange(0, phdr_num):
        phdr_type = unpack(pfmt(PHDR.p_type_size), os.read(fd, PHDR.p_type_size))[0];
        os.lseek(fd, -PHDR.p_type_size, os.SEEK_CUR)
        if phdr_type == PHDR.PT_INTERP: #phdr entry type: interp
            os.lseek(fd, PHDR.p_offset_offset, os.SEEK_CUR)
            os.write(fd, pack(pfmt(PHDR.p_offset_size), new_interp_offset))
            os.lseek(fd, -(PHDR.p_offset_offset + PHDR.p_offset_size), os.SEEK_CUR)

            os.lseek(fd, PHDR.p_vaddr_offset, os.SEEK_CUR)
            os.write(fd, pack(pfmt(PHDR.p_vaddr_size), new_interp_vaddr))
            os.lseek(fd, -(PHDR.p_vaddr_offset + PHDR.p_vaddr_size), os.SEEK_CUR)

            os.lseek(fd, PHDR.p_paddr_offset, os.SEEK_CUR)
            os.write(fd, pack(pfmt(PHDR.p_paddr_size), new_interp_paddr))
            os.lseek(fd, -(PHDR.p_paddr_offset + PHDR.p_paddr_size), os.SEEK_CUR)

            print "modifying interp offset to %lx" % new_interp_offset
            break
        os.lseek(fd, phdr_size, os.SEEK_CUR)

    #modify the interp offset in section table
    eb.modify_section_info(binname, ".interp", "offset", new_interp_offset)
    eb.modify_section_info(binname, ".interp", "addr", new_interp_vaddr)
    os.close(fd);

def extend_phdr(binname):
    global mytext_base

    #relocate_interp(binname)

    # change the original text segment to read-only
    eb.modify_phdr_info(binname, PHDR.PT_LOAD, PHDR.p_flags_offset, PHDR.PF_R)

    #now get the PHDR information
    phdr_num = eb.get_elfhdr_info(binname, "Number of program headers:");
    phdr_size = eb.get_elfhdr_info(binname,"Size of program headers:");
    phdr_start = eb.get_elfhdr_info(binname,"Start of program headers:");

    #new_ph_offset = phdr_start + phdr_num * phdr_size
    # reuse the phdr of NOTE for our new phdr
    new_ph_offset = eb.find_phdr_offset(binname, PHDR.PT_NOTE)
    if new_ph_offset == None:
        print "Ooops, we cannot reuse the PT_NOTE header"
        assert False

    mytext_mem_addr = eb.get_section_info(binname, ".mytext", "addr");
    mytext_addr = eb.get_section_info(binname, ".mytext", "offset");
    mytext_size = eb.get_section_info(binname, ".mytext", "size");	

    ptype = PHDR.PT_LOAD
    offset = mytext_addr
    segment_base = get_new_segment_base_addr(binname);
    mytext_base = segment_base + (0x00000fff & mytext_addr)

    print hex(mytext_base)

    paddr = mytext_base
    fsize = mytext_size
    memsize = fsize 
    flags = PHDR.PF_X | PHDR.PF_R # EXEC|READ
    align = 0x00001000

    print "offset of the new program header: %d" % new_ph_offset

    #change phdr header count (increment by one)
    #fd = os.open(binname, os.O_RDWR);
    #os.lseek(fd, EHDR.e_phnum_offset, os.SEEK_SET);
    #pack_fmt = pfmt(EHDR.e_phnum_size)
    #num = unpack(pack_fmt, os.read(fd, EHDR.e_phnum_size))[0];
    #print "change program header number from", num, "to", num + 1
    #os.lseek(fd, EHDR.e_phnum_offset, os.SEEK_SET);
    #os.write(fd, pack(pack_fmt, num + 1));
    #os.close(fd);

    #fill the new phdr entry with valid value
    fd = os.open(binname, os.O_RDWR);
    # type
    os.lseek(fd, new_ph_offset + PHDR.p_type_offset, os.SEEK_SET)
    os.write(fd, pack(pfmt(PHDR.p_type_size), ptype));
    # flags
    os.lseek(fd, new_ph_offset + PHDR.p_flags_offset, os.SEEK_SET)
    os.write(fd, pack(pfmt(PHDR.p_flags_size), flags));
    # offset
    os.lseek(fd, new_ph_offset + PHDR.p_offset_offset, os.SEEK_SET)
    os.write(fd, pack(pfmt(PHDR.p_offset_size), offset));
    # vaddr
    os.lseek(fd, new_ph_offset + PHDR.p_vaddr_offset, os.SEEK_SET)
    os.write(fd, pack(pfmt(PHDR.p_vaddr_size), mytext_base));
    # paddr
    os.lseek(fd, new_ph_offset + PHDR.p_paddr_offset, os.SEEK_SET)
    os.write(fd, pack(pfmt(PHDR.p_paddr_size), paddr));
    # filesz
    os.lseek(fd, new_ph_offset + PHDR.p_filesz_offset, os.SEEK_SET)
    os.write(fd, pack(pfmt(PHDR.p_filesz_size), fsize));
    # memsz
    os.lseek(fd, new_ph_offset + PHDR.p_memsz_offset, os.SEEK_SET)
    os.write(fd, pack(pfmt(PHDR.p_memsz_size), memsize));
    # align
    os.lseek(fd, new_ph_offset + PHDR.p_align_offset, os.SEEK_SET)
    os.write(fd, pack(pfmt(PHDR.p_align_size), align));
    os.close(fd);

    return

def extend_shdr(bin_name, asm_name, new_obj_name):
    new_bin_name_0 = bin_name + ".0"
    new_bin_name_1 = bin_name + ".debloated"
    new_obj_text_content_name = "new_obj_text_content"

    ret = subprocess.call(["gcc", "-c", asm_name])
    if ret != 0:
        print "compilation fails"
        exit(1)

    # copy the object text section into the original one
    eb.extract_data(new_obj_name, ".text", new_obj_text_content_name)
    cmd = ["objcopy", "--add-section", 
            ".mytext=" + new_obj_text_content_name,
            bin_name,
            new_bin_name_0]
    subprocess.call(cmd)
    eb.modify_section_info(new_bin_name_0, ".mytext", "align", 0x1000)
    # this command here is to update the location of .mytext based on the new alignment
    # as set above
    cmd = ["objcopy", new_bin_name_0, new_bin_name_1]
    subprocess.call(cmd)
    # this command is to delete the intermediate binary version
    cmd = ["rm", new_bin_name_0]
    subprocess.call(cmd)

    return new_bin_name_1

def update_shdr(bin_name, orig_asm_name, new_obj_name):
    global eb

    #fill the section table with valid value
    print "mytext_base: %lx" % mytext_base
    eb.modify_section_info(bin_name, ".mytext", "addr", mytext_base);
    eb.modify_section_info(bin_name, ".mytext", "flags", 0x00000006);#flags: ALLOC|EXEC

    with open(orig_asm_name, "r") as asm_file:
        line = asm_file.readline()
        orig_ep = line.strip().split()[1]
        new_ep_offset = eb.find_label_offset(new_obj_name, "L_" + orig_ep)
        print orig_ep, hex(new_ep_offset)
    eb.modify_elfhdr_info(bin_name, "entrypoint", mytext_base + new_ep_offset)

    return

def fix_rel(bin_name, new_obj_name):
    global eb

    fd = os.open(bin_name, os.O_RDWR)
    sec_offset = eb.get_section_info(bin_name, ".mytext", "offset")
    sec_addr = eb.get_section_info(bin_name, ".mytext", "addr")

    pattern = re.compile(r"^(?P<offset>[0-9a-fA-F]{1,16})\s+"
                          "(?P<info>[0-9a-fA-F]{1,16})\s+"
                          "(?P<type>[^\s]+)\s+"
                          "(?P<symvalue>[0-9a-fA-F]{0,16})\s+"
                          "(?P<name>[^\n]+)$")

    cmd = ["readelf", "-W", "-r", new_obj_name]
    rel_results = subprocess.check_output(cmd)
    for line in rel_results.split('\n'):
        line = line.strip()
        m = pattern.match(line)
        if m != None:
            offset = int(m.group("offset"), 16)
            type = m.group("type")
            symvalue = int(m.group("symvalue"), 16)
            name = m.group("name")

            if name.startswith("non_exist_"):
                assert type == "R_X86_64_PC32"
                # S + A - P
                # S : symbol value (should be the original function address here)
                # A : addend
                # P : offset/address of the relocated unit (the address of the relocation)
                find_start = len("non_exist_")
                find_end = name.find(" ")
                orig_addr = int(name[find_start : find_end], 16)
                addend = int(name[find_end + 1 : ], 16)
                os.lseek(fd, sec_offset + offset, os.SEEK_SET)
                os.write(fd, pack(pfmt(4), orig_addr + addend - (sec_addr + offset)))
            elif name.startswith("RIP_"):
                assert type == "R_X86_64_PC32"
                # same as above
                find_start = len("RIP_")
                find_end = name.find(" ")
                addend = int(name[find_end + 1 : ], 16)
                # label of next instruction
                label_ni = name[find_start : find_end]
                label_offset = eb.find_label_offset(new_obj_name, label_ni)
                abs_addr = label_offset + addend - offset
                value = abs_addr - (sec_addr + label_offset)
                print label_ni, hex(label_offset), "abs_addr", hex(abs_addr), hex(value)
                os.lseek(fd, sec_offset + offset, os.SEEK_SET)
                os.write(fd, pack(pfmt(4), value))
            elif name.startswith(".text"):
                if (type == "R_X86_64_32S" or type == "R_X86_64_32"):
                    # size: 4 bytes 
                    # S + A
                    find_start = len("RIP_")
                    find_end = name.find(" ")
                    addend = int(name[find_end + 1 : ], 16)
                    os.lseek(fd, sec_offset + offset, os.SEEK_SET)
                    os.write(fd, pack(pfmt(4), sec_addr + addend))
                elif (type == "R_X86_64_64"):
                    # size: 8 bytes 
                    # S + A
                    find_start = len("RIP_")
                    find_end = name.find(" ")
                    addend = int(name[find_end + 1 : ], 16)
                    os.lseek(fd, sec_offset + offset, os.SEEK_SET)
                    os.write(fd, pack(pfmt(8), sec_addr + addend))
                else:
                    assert False



    return

def fix_ctors_dtors(binname, new_obj_name):
    # it seems we do not have to fix ctors, which are actually invoked 
    # by __libc_csu_init (in the main bin)
    #
    # so we only care about dtors
    global mytext_base, eb

    fini_array_sec_size = eb.get_section_info(binname, ".fini_array", "size")
    fini_array_sec_offset = eb.get_section_info(binname, ".fini_array", "offset")
    print hex(fini_array_sec_size), hex(fini_array_sec_offset)
    if fini_array_sec_size == 0 or fini_array_sec_size == None:
        return

    fd = os.open(binname, os.O_RDWR)
    os.lseek(fd, fini_array_sec_offset, os.SEEK_SET)

    eleNum = fini_array_sec_size / 8
    for idx in xrange(0, eleNum):
        value = unpack(pfmt(ARCH.INT_SIZE), os.read(fd, ARCH.INT_SIZE))[0]
        label_name = "L_0x%x" % value
        label_new_offset = eb.find_label_offset(new_obj_name, label_name)
        print label_name, hex(label_new_offset)
        label_new_addr = mytext_base + label_new_offset
        os.lseek(fd, -ARCH.INT_SIZE, os.SEEK_CUR)
        os.write(fd, pack(pfmt(ARCH.INT_SIZE), label_new_addr))

def fix__fini(binname, new_obj_name):
    # TODO: handle _fini in symbol table
    global my_text_base, eb

    _fini_value = eb.read_dynamic_option(binname, DYNAMIC.DT_FINI)
    label_name = "L_0x%x" % _fini_value
    print label_name
    label_new_offset = eb.find_label_offset(new_obj_name, label_name)

    # _fini is never executed
    if label_new_offset == None:
        return

    label_new_addr = mytext_base + label_new_offset
    eb.update_dynamic_option(binname, DYNAMIC.DT_FINI, label_new_addr)

def fix_symtab(binname, new_obj_name):
    global my_text_base, eb

    dynsym_sec_offset = eb.get_section_info(binname, ".symtab", "offset")
    dynsym_sec_entry_size = eb.get_section_info(binname, ".symtab", "entrysize")
    dynsym_sec_size = eb.get_section_info(binname, ".symtab", "size")
    print dynsym_sec_size
    print dynsym_sec_entry_size
    dynsym_sec_entry_num =  dynsym_sec_size / dynsym_sec_entry_size
    
    fd = os.open(binname, os.O_RDWR)
    os.lseek(fd, dynsym_sec_offset, os.SEEK_SET)
    for index in xrange(0, dynsym_sec_entry_num):
        #os.lseek(fd, SYMT.st_shndx_offset, os.SEEK_CUR)
        #shndx = unpack(pfmt(SYMT.st_shndx_size), os.read(fd, SYMT.st_shndx_size))[0]
        #os.lseek(fd, -(SYMT.st_shndx_offset + SYMT.st_shndx_size), os.SEEK_CUR)
        #if shndx != 0:
        os.lseek(fd, SYMT.st_value_offset, os.SEEK_CUR)
        value = unpack(pfmt(SYMT.st_value_size), os.read(fd, SYMT.st_value_size))[0]
        os.lseek(fd, -(SYMT.st_value_offset + SYMT.st_value_size), os.SEEK_CUR)
        if value != 0:
            os.lseek(fd, SYMT.st_info_offset, os.SEEK_CUR)
            info = unpack(pfmt(SYMT.st_info_size), os.read(fd, SYMT.st_info_size))[0]
            os.lseek(fd, -(SYMT.st_info_offset + SYMT.st_info_size), os.SEEK_CUR)
            stype = ST_TYPE(info)
            #print "type", stype
            if stype == SYMT.STT_FUNC:
                print index, value, stype
                os.lseek(fd, SYMT.st_value_offset, os.SEEK_CUR)
                value = unpack(pfmt(SYMT.st_value_size), os.read(fd, SYMT.st_value_size))[0]
                os.lseek(fd, -(SYMT.st_value_offset + SYMT.st_value_size), os.SEEK_CUR)
                print hex(value)
                label = "L_0x%x" % value
                print label
                new_offset = eb.find_label_offset(new_obj_name, label)
                if new_offset != None:
                    new_addr = mytext_base + new_offset
                    print hex(new_addr)
                    os.lseek(fd, SYMT.st_value_offset, os.SEEK_CUR)
                    value = pack(pfmt(SYMT.st_value_size), new_addr)
                    os.write(fd, value)
                    os.lseek(fd, -(SYMT.st_value_offset + SYMT.st_value_size), os.SEEK_CUR)
        os.lseek(fd, dynsym_sec_entry_size, os.SEEK_CUR)

def fix_dynsym(binname, new_obj_name):
    global my_text_base, eb

    dynsym_sec_offset = eb.get_section_info(binname, ".dynsym", "offset")
    dynsym_sec_entry_size = eb.get_section_info(binname, ".dynsym", "entrysize")
    dynsym_sec_size = eb.get_section_info(binname, ".dynsym", "size")
    print dynsym_sec_size
    print dynsym_sec_entry_size
    dynsym_sec_entry_num =  dynsym_sec_size / dynsym_sec_entry_size
    
    fd = os.open(binname, os.O_RDWR)
    os.lseek(fd, dynsym_sec_offset, os.SEEK_SET)
    for index in xrange(0, dynsym_sec_entry_num):
        #os.lseek(fd, SYMT.st_shndx_offset, os.SEEK_CUR)
        #shndx = unpack(pfmt(SYMT.st_shndx_size), os.read(fd, SYMT.st_shndx_size))[0]
        #os.lseek(fd, -(SYMT.st_shndx_offset + SYMT.st_shndx_size), os.SEEK_CUR)
        #if shndx != 0:
        os.lseek(fd, SYMT.st_value_offset, os.SEEK_CUR)
        value = unpack(pfmt(SYMT.st_value_size), os.read(fd, SYMT.st_value_size))[0]
        os.lseek(fd, -(SYMT.st_value_offset + SYMT.st_value_size), os.SEEK_CUR)
        if value != 0:
            os.lseek(fd, SYMT.st_info_offset, os.SEEK_CUR)
            info = unpack(pfmt(SYMT.st_info_size), os.read(fd, SYMT.st_info_size))[0]
            os.lseek(fd, -(SYMT.st_info_offset + SYMT.st_info_size), os.SEEK_CUR)
            stype = ST_TYPE(info)
            #print "type", stype
            if stype == SYMT.STT_FUNC:
                print index, value, stype
                os.lseek(fd, SYMT.st_value_offset, os.SEEK_CUR)
                value = unpack(pfmt(SYMT.st_value_size), os.read(fd, SYMT.st_value_size))[0]
                os.lseek(fd, -(SYMT.st_value_offset + SYMT.st_value_size), os.SEEK_CUR)
                print hex(value)
                label = "L_0x%x" % value
                print label
                new_offset = eb.find_label_offset(new_obj_name, label)
                if new_offset != None:
                    new_addr = mytext_base + new_offset
                    print hex(new_addr)
                    os.lseek(fd, SYMT.st_value_offset, os.SEEK_CUR)
                    value = pack(pfmt(SYMT.st_value_size), new_addr)
                    os.write(fd, value)
                    os.lseek(fd, -(SYMT.st_value_offset + SYMT.st_value_size), os.SEEK_CUR)
        os.lseek(fd, dynsym_sec_entry_size, os.SEEK_CUR)
        

def merge_bin_asm(orig_bin_path, orig_asm_path):
    global eb
    eb = elf_basic()

    eb.initELF(orig_bin_path)

    print "the orignal binary is", orig_bin_path
    print "the executed asm is", orig_asm_path

    orig_bin_name = os.path.basename(orig_bin_path)
    orig_asm_name = os.path.basename(orig_asm_path)
    new_obj_name = orig_asm_name[:-2] + ".o"
    work_dir = orig_bin_name + "_temp"

    # generate the object file
    subprocess.call(["mkdir", "-p", work_dir])
    subprocess.call(["cp", orig_bin_path, work_dir])
    subprocess.call(["cp", orig_asm_path, work_dir])
    os.chdir("./" + work_dir)

    # add the asm into the bin as a new section
    bin_name = extend_shdr(orig_bin_name, orig_asm_name, new_obj_name)

    # add a new phdr for the new section
    extend_phdr(bin_name)

    # update the new section
    update_shdr(bin_name, orig_asm_name, new_obj_name)

    # fix relocations in .mytext
    fix_rel(bin_name, new_obj_name)

    # fix constructor and destructor
    fix_ctors_dtors(bin_name, new_obj_name)

    # fix the _fini symbol in DYNAMIC and symbol
    fix__fini(bin_name, new_obj_name)

    # fix the functions in dynamic symbol section, which could
    # be used by other libraries, like redefined new() in C++
    fix_dynsym(bin_name, new_obj_name)
    fix_symtab(bin_name, new_obj_name)

    eb.analyze_eh_frame_hdr(bin_name, new_obj_name, mytext_base)
    print "elf_frame_hdr_less", hex(eb.elf_frame_hdr_less)
    eb.analyze_eh_frame(bin_name, new_obj_name, mytext_base)
    print "uleb128_less", hex(eb.uleb128_less)
    print "uleb128_more", hex(eb.uleb128_more)

def main():

    parser = argparse.ArgumentParser()
    parser.add_argument('binfile', nargs=1)
    parser.add_argument('asmfile', nargs=1)
    args = parser.parse_args()

    orig_bin_path = args.binfile[0]
    orig_asm_path = args.asmfile[0]

    merge_bin_asm(orig_bin_path, orig_asm_path)

if __name__ == "__main__":
    main()
