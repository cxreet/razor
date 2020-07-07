#!/usr/bin/python
from __future__ import with_statement
from struct import *
from elf_headers import *

#from __future__ import with_statement
import re
import os
import sys
import math
import random
import string
import ctypes
import argparse
import subprocess

sys.dont_write_bytecode = True

def align(value_to_align, alignment):
    return ((value_to_align + alignment - 1) / alignment) * alignment

class elf_basic(object):

    instance = None;
    binname = None

    @classmethod
    def __init__(self):
        self.offset_dynamic = 0
        self.foff_ef2cie = {}
        self.fde_table = []

        self.uleb128_more = 0
        self.uleb128_less = 0
        self.elf_frame_hdr_less = 0

        self.is_eh_frame_hdr_after_eh_frame = False
        
        self.eh_frame_hdr_align = None
        self.eh_frame_hdr_foff = None
        self.eh_frame_hdr_size = None
        self.eh_frame_hdr_addr = None

        self.eh_frame_align = None
        self.old_eh_frame_foff = None
        self.new_eh_frame_foff = None
        self.old_eh_frame_addr = None
        self.new_eh_frame_addr = None
        self.eh_frame_size = None
        self.eh_frame_shift_offset = None

        # get means ".gcc_except_table"
        self.has_get = False
        self.get_align = None
        self.old_get_foff = None
        self.new_get_foff = None
        self.old_get_addr = None
        self.new_get_addr = None
        self.old_get_size = None
        self.new_get_size = None
        self.get_shift_offset = None

        self.exec_addr = None
        self.exec_size = None

        self.sym2off_cache = {}
        self.sym_off_array = None
        self.sym2off_cache_keys = None

        elf_basic.instance = self;

    def initELF(self, binname):

        exec_start, exec_end = self.get_exec_memory_range(binname)
        self.exec_addr = exec_start
        self.exec_size = exec_end - exec_start


    def getELFobject(cls):
        if(cls.instance !=None):
            return cls.instance;
        else:
            cls.instance = elf_basic()
            return cls.instance

    def myprint(self):
        print "this is a test of elf_basic"

    def get_elfhdr_info(self, binpath, attribute):
        elfhdr_pa = re.compile(r'[^:]:\s*[^\n]$');

        cmd = "readelf -h ";
        cmd += binpath;
        with os.popen(cmd) as file:
            for line in file:
                line = line.rstrip()
                if attribute in line:
                    str = line.split(':');
                    str = str[1].strip();
                    str = str.split(' ');
                    if(attribute == "Entry point address:"):
                        info = str[0];
                    elif(attribute == "Type:"):
                        info = str[0];
                    else:
                        info = str[0];
                        info = int(str[0],10);
                    #print info;

        return info

    def convert_vma_to_offset(self, binname, vma):
        vma = int(vma, 16)
        num = self.get_elfhdr_info(binname, "Number of section headers:")
        pattern = re.compile(r"\s*\[\s*(?P<num>[\d]{1,2})\]\s*"
                "(?P<name>[\S]+)\s*"
                "(?P<type>[\S]+)\s*"
                "(?P<addr>[\S]+)\s*"
                "(?P<offset>[\S]+)\s*"
                "(?P<size>[\S]+)\s*"
                "[^\n]*$")

        cmd = "readelf -S " + binname;
        with os.popen(cmd) as file:
            for line in file:
                line = line.strip();
                m=pattern.match(line);
                if(m != None):
                    vma_start = int(m.group('addr'),16)
                    size = int(m.group('size'),16)
                    if(((vma_start+size) <= vma) or (vma < vma_start)):
                        continue
                    else:    
                        if(m.group('name') == '.bss'):
                            return int(m.group('offset'),16) 
                        else:
                            offset_start = int(m.group('offset'), 16)
                            offset = offset_start + (vma - vma_start)
                            return offset 
        return 0

    def get_section_info(self, binname, secname, info):
        pattern = re.compile(r"\s*\[\s*(?P<num>[\d]{1,2})\]\s*"
                "(?P<name>[\S]+)\s*"
                "(?P<type>[\S]+)\s*"
                "(?P<addr>[\S]+)\s*"
                "(?P<offset>[\S]+)\s*"
                "(?P<size>[\S]+)\s*"
                "(?P<entrysize>[\S]+)\s*"
                "(?P<flags>[ WAXMSlILGTExOop]*)\s+"
                "(?P<link>[\d]{1,8})\s*"
                "(?P<info>[\d]{1,8})\s*"
                "(?P<align>[\d]{1,8})\s*"
                "[^\n]*$")
        cmd = "readelf -WS " + binname;
        with os.popen(cmd) as file:
            for line in file:
                line = line.strip();
                m = pattern.match(line);
                if((m != None) and (m.group('name') == secname)):
                    if(info == 'num'):
                        return int(m.group(info),10)
                    if((info == 'addr') or (info == 'offset') or 
                       (info == 'size') or (info == "entrysize")):
                        return int(m.group(info),16)
                    elif ((info == "link") or (info == "info") or
                          (info == "align")):
                        return int(m.group(info))
                    else:
                        return m.group(info)
                    return m.group(info)
        return None

    def modify_elfhdr_info(self, binpath, attribute, value):
        fd = os.open(binpath, os.O_RDWR);
        if(attribute == "entrypoint"):
            os.lseek(fd, EHDR.e_entry_offset, os.SEEK_SET);
            value = pack(pfmt(EHDR.e_entry_size), value);
            os.write(fd, value);
            value = unpack(pfmt(EHDR.e_entry_size), value)
            print "modify entry point to %lx\n" % value;
        else:
            print "not supported attribute:", attribute

        os.close(fd);

    def modify_phdr_info(self, binname, seg_type, in_seg_offset, value):
        phdr_num = self.get_elfhdr_info(binname, "Number of program headers:");
        phdr_size = self.get_elfhdr_info(binname,"Size of program headers:");
        phdr_start = self.get_elfhdr_info(binname,"Start of program headers:");
        fd = os.open(binname, os.O_RDWR);
        # go to the beginning of the program headers
        os.lseek(fd, phdr_start, os.SEEK_SET)
        p_offset = 0

        for idx in xrange(0, phdr_num):
            os.lseek(fd, PHDR.p_type_offset, os.SEEK_CUR)
            ptype = unpack(pfmt(PHDR.p_type_size), os.read(fd, PHDR.p_type_size))[0];
            os.lseek(fd, -(PHDR.p_type_offset + PHDR.p_type_size), os.SEEK_CUR)
            #print "idx:%x, type:%x" % (idx, ptype)
            if(ptype == seg_type):
                break
            os.lseek(fd, phdr_size, os.SEEK_CUR)

        os.lseek(fd, in_seg_offset, os.SEEK_CUR)
        attribute_size = PHDR.offset2size[in_seg_offset]
        os.write(fd, pack(pfmt(attribute_size), value));

        os.close(fd)

    def find_phdr_offset(self, binname, seg_type):
        phdr_num = self.get_elfhdr_info(binname, "Number of program headers:");
        phdr_size = self.get_elfhdr_info(binname,"Size of program headers:");
        phdr_start = self.get_elfhdr_info(binname,"Start of program headers:");
        fd = os.open(binname, os.O_RDWR);
        # go to the beginning of the program headers
        os.lseek(fd, phdr_start, os.SEEK_SET)
        p_offset = 0

        for idx in xrange(0, phdr_num):
            os.lseek(fd, PHDR.p_type_offset, os.SEEK_CUR)
            ptype = unpack(pfmt(PHDR.p_type_size), os.read(fd, PHDR.p_type_size))[0];
            os.lseek(fd, -(PHDR.p_type_offset + PHDR.p_type_size), os.SEEK_CUR)
            #print "idx:%x, type:%x" % (idx, ptype)
            if(ptype == seg_type):
                cur_pos = os.lseek(fd, 0, os.SEEK_CUR)
                os.close(fd)
                return cur_pos
            os.lseek(fd, phdr_size, os.SEEK_CUR)

        os.close(fd)
        return None

    def get_phdr_info(self, binname, seg_type, in_seg_offset):
        phdr_num = self.get_elfhdr_info(binname, "Number of program headers:");
        phdr_size = self.get_elfhdr_info(binname,"Size of program headers:");
        phdr_start = self.get_elfhdr_info(binname,"Start of program headers:");
        fd = os.open(binname, os.O_RDWR);
        # go to the beginning of the program headers
        os.lseek(fd, phdr_start, os.SEEK_SET)
        p_offset = 0

        for idx in xrange(0, phdr_num):
            os.lseek(fd, PHDR.p_type_offset, os.SEEK_CUR)
            ptype = unpack(pfmt(PHDR.p_type_size), os.read(fd, PHDR.p_type_size))[0];
            os.lseek(fd, -(PHDR.p_type_offset + PHDR.p_type_size), os.SEEK_CUR)
            #print "idx:%x, type:%x" % (idx, ptype)
            if(ptype == seg_type):
                break
            os.lseek(fd, phdr_size, os.SEEK_CUR)

        os.lseek(fd, in_seg_offset, os.SEEK_CUR)
        attribute_size = PHDR.offset2size[in_seg_offset]
        
        value = unpack(pfmt(attribute_size), os.read(fd, attribute_size))[0]
        os.close(fd)

        return value

    def modify_section_info(self, binpath, secname, attribute, value):
        secnum = self.get_section_info(binpath, secname, "num")
        if(secnum == None):
            print "section %s does not exists\n" % secname;
            return
        sectable_start = self.get_elfhdr_info(binpath, "Start of section headers:")
        section_size = self.get_elfhdr_info(binpath, "Size of section headers:")
        section_offset = sectable_start + secnum * section_size

        if(attribute == "index"):
            offset = SHDR.sh_name_offset
        elif(attribute == "type"):
            offset = SHDR.sh_type_offset
        elif(attribute == "flags"):
            offset = SHDR.sh_flags_offset
        elif(attribute == "addr"):
            offset = SHDR.sh_addr_offset
        elif(attribute == "offset"):
            offset = SHDR.sh_offset_offset
        elif(attribute == "size"):
            offset = SHDR.sh_size_offset
        elif(attribute == "link"):
            offset = SHDR.sh_link_offset
        elif(attribute == "info"):
            offset = SHDR.sh_info_offset
        elif(attribute == "align"):
            offset = SHDR.sh_align_offset
        elif(attribute == "entsize"):
            offset = SHDR.sh_entrize_offset

        attribute_offset = section_offset + offset
        attribute_size = SHDR.offset2size[offset]
        pack_fmt = pfmt(attribute_size)

        fd = os.open(binpath, os.O_RDWR);
        os.lseek(fd, attribute_offset, os.SEEK_SET);
        os.write(fd, pack(pack_fmt, value));
        os.close(fd);

    def get_relocation_info(self, binname):
	pattern = re.compile(r"^(?P<offset>[0-9a-fA-F]{1,16})\s+"
			      "(?P<info>[0-9a-fA-F]{1,16})\s+"
                              "(?P<type>[^\s]+)\s+"
		              "(?P<symvalue>[0-9a-fA-F]{0,16})\s+"
		              "(?P<name>[^\n]+)$")
	cmd = ["readelf", "-rW", binname]
	relocation_results = subprocess.check_output(cmd)
	find_rela_plt = False
        relocations_in_rela_plt = []
	for line in relocation_results.split('\n'):
            line = line.strip()
            if find_rela_plt == False:
                if ".rela.plt" in line:
                    find_rela_plt = True
                else:
                    continue
            else:
                m = pattern.match(line)
                if m != None:
                    relocations_in_rela_plt.append({"offset" : int(m.group("offset"), 16), 
                                                    "info"   : int(m.group("info"), 16),
                                                    "type"   : m.group("type"),
                                                    "symvalue" : int(m.group("symvalue"), 16),
                                                    "name"   : m.group("name")
                                                    })
        return relocations_in_rela_plt




    def get_dynamic_offset_size(self, binname):
        phdr_num = self.get_elfhdr_info(binname, "Number of program headers:");
        phdr_size = self.get_elfhdr_info(binname,"Size of program headers:");
        phdr_start = self.get_elfhdr_info(binname,"Start of program headers:");

        dyn_offset = 0;
        dyn_infile_size = 0;

        fd_phdr = os.open(binname, os.O_RDWR);
        os.lseek(fd_phdr, phdr_start, os.SEEK_SET)
        for size in xrange(0, phdr_num):
            phdr_type = unpack(pfmt(PHDR.p_type_size), os.read(fd_phdr, PHDR.p_type_size))[0];
            os.lseek(fd_phdr, -PHDR.p_type_size, os.SEEK_CUR);
            if phdr_type == PHDR.PT_DYNAMIC: #phdr entry type: dynamic
                os.lseek(fd_phdr, PHDR.p_offset_offset, os.SEEK_CUR);
                dyn_offset = unpack(pfmt(PHDR.p_offset_size), os.read(fd_phdr, PHDR.p_offset_size))[0]
                self.offset_dynamic = dyn_offset
                os.lseek(fd_phdr, -(PHDR.p_offset_offset + PHDR.p_offset_size), os.SEEK_CUR)

                os.lseek(fd_phdr, PHDR.p_filesz_offset, os.SEEK_CUR)
                dyn_infile_size = unpack(pfmt(PHDR.p_filesz_size), os.read(fd_phdr, PHDR.p_filesz_size))[0]
                os.close(fd_phdr);
                return dyn_offset, dyn_infile_size
            os.lseek(fd_phdr, phdr_size, os.SEEK_CUR)

        os.close(fd_phdr);
        return None, None

    def add_dynamic_option(self, binname, option, value):    

        dyn_offset, dyn_infile_size = self.get_dynamic_offset_size(binname)

        print "offset of dynamic segment: %lx" % dyn_offset
        print "size of dynamic segment: %lx" % dyn_infile_size

        fd = os.open(binname,os.O_RDWR);
        os.lseek(fd, dyn_offset, os.SEEK_SET);
        #os.lseek(fd, dyn_offset + dyn_infile_size - 8, os.SEEK_SET);
        print "move to beginning of dynamic segment: %lx" % (dyn_offset )

        dyn_start = dyn_offset;
        dyn_end = dyn_offset + dyn_infile_size - 8;
        enlarge_dynamic = 1;
        opt_size = DYNAMIC.opt_size
        value_size = DYNAMIC.value_size
        entry_size = opt_size + value_size
        while (dyn_start < dyn_end):
            dyn_option = unpack(pfmt(opt_size), os.read(fd, opt_size))[0];
            dyn_content = unpack(pfmt(value_size), os.read(fd, value_size))[0];
            if(dyn_option == 0 and dyn_content == 0):
                #reach the end of dynamic segment
                enlarge_dynamic = 0;
                os.lseek(fd, entry_size, os.SEEK_CUR);
                os.write(fd,pack(pfmt(opt_size), option));#0x18 means BIND_NOW
                os.write(fd,pack(pfmt(value_size), value));
                break;
            dyn_start += entry_size;

        #enlarge the dynamic segment by 8 bytes
        if(enlarge_dynamic == 1):
            os.write(fd, pack(pfmt(opt_size), option));#0x18 means BIND_NOW
            os.write(fd, pack(pfmt(value_size), value));
            os.write(fd, pack(pfmt(opt_size), 0x00000000));
            os.write(fd, pack(pfmt(value_size), 0x00000000));
            os.write(fd_phdr, pack(pfmt(opt_size), dyn_infile_size + entry_size))
            os.write(fd_phdr, pack(pfmt(value_size), dyn_infile_size + entry_size))

        os.close(fd)

    def read_dynamic_option(self, binname, option):
        dyn_offset, dyn_infile_size = self.get_dynamic_offset_size(binname)
        fd = os.open(binname, os.O_RDWR);
        os.lseek(fd, dyn_offset, os.SEEK_SET);

        opt_size = DYNAMIC.opt_size
        value_size = DYNAMIC.value_size
        dyn_opt = unpack(pfmt(opt_size), os.read(fd, opt_size))[0];
        while(dyn_opt != 0):
            #print "dynamic option type: %d"%dyn_opt
            dyn_value = unpack(pfmt(DYNAMIC.value_size), os.read(fd, DYNAMIC.value_size))[0];
            if(dyn_opt == option):
                os.close(fd);
                return dyn_value
            dyn_opt = unpack(pfmt(DYNAMIC.opt_size), os.read(fd, DYNAMIC.opt_size))[0];

        os.close(fd)
        return None

    def read_dynamic_option_all(self, binname, option):
        dyn_offset, dyn_infile_size = self.get_dynamic_offset_size(binname)
        fd = os.open(binname, os.O_RDWR);
        os.lseek(fd, dyn_offset, os.SEEK_SET);

        opt_size = DYNAMIC.opt_size
        value_size = DYNAMIC.value_size
        dyn_opt = unpack(pack_fmt, os.read(fd, opt_size))[0];
        result = []
        while(dyn_opt != 0):
            #print "dynamic option type: %d"%dyn_opt
            dyn_value = unpack(pfmt(value_size), os.read(fd, value_size))[0];
            if(dyn_opt == option):
                result.append(dyn_value)
            dyn_opt = unpack(pfmt(opt_size), os.read(fd, opt_size))[0];

        os.close(fd)
        return result

    def update_dynamic_option(self, binname, option, new_value):
        dyn_offset, dyn_infile_size = self.get_dynamic_offset_size(binname)
        fd = os.open(binname,os.O_RDWR);
        os.lseek(fd, dyn_offset, os.SEEK_SET);

        opt_size = DYNAMIC.opt_size
        value_size = DYNAMIC.value_size
        dyn_opt = unpack(pfmt(opt_size), os.read(fd, opt_size))[0];
        while(dyn_opt != 0):
            #print "dynamic option type: %d"%dyn_opt
            if(dyn_opt == option):
                os.write(fd, pack(pfmt(value_size), new_value));
                os.close(fd);
                return 1;
            dyn_value = unpack(pfmt(value_size), os.read(fd, value_size))[0];
            dyn_opt = unpack(pfmt(opt_size), os.read(fd, opt_size))[0];

        os.close(fd)
        return None

    def get_exec_memory_range(self, binpath):
        #step 1: get code memory range
        cmd="readelf -W -S "+binpath+'| sed \'s/\[\s*//g\'|grep \' AX \'| awk \'{print $4 \" \" $5 \" \" $6}\''
        pattern = re.compile(r"^(\S+)\s+(\S+)\s+(\S+)");
        exec_begin = 0x7fffffff;
        exec_end = 0x0;
        exec_end_size = 0;
        with os.popen(cmd) as file:
            for line in file:
                line = line.strip()
                m = pattern.match(line);
                if(m != None):
                    #print line
                    #print m.group(1);
                    addr = int(m.group(1), 16);
                    size = int(m.group(3), 16);
                    if(addr < exec_begin):
                        exec_begin = addr
                    if(addr > exec_end):
                        exec_end = addr
                        exec_end_size = size;
            exec_end += exec_end_size;
            #print "exec_begin %x"%exec_begin
            #print "exec_end %x"%exec_end
        return (exec_begin, exec_end)

    def extract_data(self, binname,secname,output):
        data_offset = self.get_section_info(binname, secname, "offset");    
        data_size = self.get_section_info(binname, secname, "size");
        if(data_offset == None):
            print "extract_data: "+binname+" file does not exist";
            return;
        fd = os.open(binname,os.O_RDWR);
        os.lseek(fd, data_offset, os.SEEK_SET);
        buf = os.read(fd, data_size);
        fd2 = os.open(output, os.O_CREAT|os.O_TRUNC|os.O_RDWR, 0644)
        os.write(fd2, buf);
        os.close(fd2);
        os.close(fd);

    def find_next_offset(self, binname, symbolname):
        assert symbolname.startswith("L_0x")
        orig_offset = int(symbolname[4:], 16) - self.exec_addr

        if self.binname != binname:
            # just refresh the cache
            self.find_label_offset(binname, symbolname)

        new_offset = self.sym_off_array[orig_offset][0]
        if new_offset != None:
            return new_offset

        while orig_offset < self.exec_size:
            orig_offset = self.sym_off_array[orig_offset][1]
            new_offset = self.sym_off_array[orig_offset][0]
            if new_offset != None:
                return new_offset
        return None

    def find_label_offset(self, binname, symbolname):
        if symbolname == None:
            # FIXME: a large number
            return 0xffffff

        if self.binname != binname:
            self.binname = binname
            #print binname

            if self.sym_off_array == None:
                self.sym_off_array = [[None,None] for x in xrange(0, self.exec_size)]

            self.sym2off_cache.clear()
            pattern = re.compile(r"^(?P<number>[0-9]{1,16}:)\s+"
                                   "(?P<value>[0-9a-fA-F]{1,16})\s+"
                                   "(?P<size>[0-9a-fA-F]{1,8})\s+"
                                   "(?P<type>[A-Z]{1,20})\s+"
                                   "(?P<bind>[A-Z]{1,10})\s+"
                                   "(?P<bis>[A-Z]{1,10})\s+"
                                   "(?P<ndx>[A-Za-f0-9]{1,8})\s+"
                                   "(?P<name>[^\n]*)$");

            cmd = ["readelf", "-sW", binname]
            symbol_results = subprocess.check_output(cmd)
            for line in symbol_results.split('\n'):
                line = line.strip()
                m = pattern.match(line)
                if m != None:
                    name = m.group("name")
                    offset = int(m.group("value"), 16)
                    if offset == 0:
                        continue
                    if name.startswith("L_0x"):
                        orig_offset = int(name[4:], 16) - self.exec_addr
                        self.sym_off_array[orig_offset][0] = offset
                    else:
                        self.sym2off_cache[name] = offset

            last_index = self.exec_size - 1
            if self.sym_off_array[last_index][0] == None:
                self.sym_off_array[last_index][0] = 0xffffff
                self.sym_off_array[last_index][1] = last_index
            for index in xrange(self.exec_size - 1, -1, -1):
                #print hex(index), "--->", hex(last_index)
                self.sym_off_array[index][1] = last_index
                if self.sym_off_array[index][0] != None:
                    last_index = index

            self.sym2off_cache_keys = self.sym2off_cache.keys()
            self.sym2off_cache_keys.sort()

        if symbolname.startswith("L_0x"):
            orig_offset = int(symbolname[4:], 16) - self.exec_addr
            return self.sym_off_array[orig_offset][0]
        elif symbolname in self.sym2off_cache:
            return self.sym2off_cache[symbolname]
        else:
            return None

    def compile_inject_data(self, htables, binname):
        for h in htables:
            base = os.path.basename(h.output_data)
            raw = base.split('.')[0] #eliminate the extention name
            cmd = "gcc -c " + base
            os.system(cmd)
            obj = raw + ".o"
            sec = h.get_secname();

            self.extract_data(obj, ".text", raw)

            cmd = "objcopy --add-section " + sec + "=" + raw + " " + binname + " " + binname
            print "%s" % cmd
            os.system(cmd)
            self.modify_section_info(binname, sec, "align", 0x00001000)

    def get_segment_info(self, binname, segtype):
        pattern = re.compile(r"^(?P<type>[_A-Z]{1,20})\s+"
                               "(?P<offset>[x0-9a-fA-F]{1,18})\s+"
                               "(?P<vaddr>[x0-9a-fA-F]{1,18})\s+"
                               "(?P<paddr>[x0-9a-fA-F]{1,18})\s+"
                               "(?P<filesz>[x0-9a-fA-F]{1,18})\s+"
                               "(?P<memsz>[x0-9a-fA-F]{1,18})\s+"
                               "(?P<flags>[ RWE]{3})\s+"
                               "(?P<align>[^\n]*)$");
        cmd = ["readelf", "-Wl", binname]
        segment_results = subprocess.check_output(cmd)
        result = []
        for line in segment_results.split('\n'):
            line = line.strip()
            m = pattern.match(line)
            if m != None:
                if m.group("type") == segtype or segtype == "*":
                    seg_info = {"type" : m.group("type"),
                                "offset" : m.group("offset"),
                                "vaddr" : m.group("vaddr"),
                                "paddr" : m.group("paddr"),
                                "filesz" : m.group("filesz"),
                                "memsz" : m.group("memsz"),
                                "flags" : m.group("flags"),
                                "align" : m.group("align")
                                }
                    result.append(seg_info)

        return result

    # Here is my idea to create more space in the ELF file so that we can freely (to some extent) edit
    # the .gcc_except_table section:
    # 
    # The .eh_frame_hdr will have one entry for each function in its fde table (each entry contains function
    # starting address, and offset to the fde object in .eh_frame). In the debloated binary, we will not have
    # so many functions any more. Therefore, the fde table inside .eh_frame_hdr can be shorten to provide
    # more space. 
    #
    # There are two cases of the layout of ELF (at least I have seen two, maybe more are possible)
    # 
    # 1. .eh_frame_hdr
    #    .eh_frame
    #    .gcc_except_table
    # 
    # 2. .eh_frame
    #    .eh_frame_hdr
    #    [.gcc_except_table]
    #
    # In case 1, we keep the starting address of .eh_frame_hdr unchanged, but will shrink it. Due to the missing
    # functions in the debloated binary, we will see holes in the fde table. Our work is to bring the left fde 
    # entry forward if necessary, to avoid the holes. At the same time, we have to update the number of fdes, and
    # the offset of the real fde object in .eh_frame. 
    # 
    # Then we also need to move the .eh_frame section forward, to start immediately (with the consideration of
    # alignment requirement) after the new fde table in .eh_frame_hdr. Of course, we have to fix the reference
    # to .gcc_except_table entries (lsda)
    # 
    # The last step is to bring .gcc_except_table section forward, immediately (considering alignment) after the
    # new .eh_frame section.
    # 
    # Case 1 is the most common case, and this is also the case I first wrote the code for. However, it turns out
    # that the Case 2 is also possible (in some small programs, at least). So I have to take this case into
    # consideration.
    #
    # In case 2, we do not have to shift the .eh_frame section, but still have to update its reference to lsda.
    # 
    # Then we have to shrink the fde table in .eh_frame_hdr again.
    # 
    # At last, we will bring the .gcc_except_table forward, immediately (considering the alignment) after the new
    # fde table in .eh_frame_hdr
    #
    # NOTE: In both cases, we do not change the starting address of .eh_frame_hdr, and do not change the size of 
    # .eh_frame.
    #
    def analyze_eh_frame_hdr(self, binname, new_obj_name, mytext_base, patch=True):
        print "\n\nParsing .eh_frame_hdr section"
        foff_efh = 0

        self.eh_frame_hdr_align = self.get_section_info(binname, ".eh_frame_hdr", "align")
        self.eh_frame_hdr_foff = self.get_section_info(binname, ".eh_frame_hdr", "offset")
        self.eh_frame_hdr_size = self.get_section_info(binname, ".eh_frame_hdr", "size")
        self.eh_frame_hdr_addr = self.get_section_info(binname, ".eh_frame_hdr", "addr")

        self.old_eh_frame_foff = self.get_section_info(binname, ".eh_frame", "offset")
        self.old_eh_frame_addr = self.get_section_info(binname, ".eh_frame", "addr")
        self.eh_frame_align = self.get_section_info(binname, ".eh_frame", "align")
        self.eh_frame_size = self.get_section_info(binname, ".eh_frame", "size")

        if (align(self.eh_frame_hdr_foff + self.eh_frame_hdr_size, self.eh_frame_align) != self.old_eh_frame_foff):
            print "eh_frame_hdr_foff:", hex(self.eh_frame_hdr_foff)
            print "eh_frame_hdr_size:", hex(self.eh_frame_hdr_size)
            print "eh_frame_align:   ", hex(self.eh_frame_align)
            print "eh_frame_hdr end: ", hex(align(self.eh_frame_hdr_foff + self.eh_frame_hdr_size, self.eh_frame_hdr_align))
            print "eh_frame_foff:    ", hex(self.old_eh_frame_foff)
            self.is_eh_frame_hdr_after_eh_frame = True

        self.get_align = self.get_section_info(binname, ".gcc_except_table", "align")
        if self.get_align == None:
            self.has_get = False
        else:
            self.has_get = True
            self.old_get_foff = self.get_section_info(binname, ".gcc_except_table", "offset")
            self.old_get_addr = self.get_section_info(binname, ".gcc_except_table", "addr")
            self.old_get_size = self.get_section_info(binname, ".gcc_except_table", "size")

        fd_read = os.open(binname, os.O_RDONLY)
        os.lseek(fd_read, self.eh_frame_hdr_foff, os.SEEK_SET)

        eh_frame_hdr = EH_FRAME_HDR()
        eh_frame_hdr.addr = self.eh_frame_hdr_addr

        # get the header
        eh_frame_hdr.version = unpack("<B", os.read(fd_read, 1))[0]
        eh_frame_hdr.eh_frame_ptr_enc = unpack("<B", os.read(fd_read, 1))[0]
        eh_frame_hdr.fde_count_enc = unpack("<B", os.read(fd_read, 1))[0]
        eh_frame_hdr.table_enc = unpack("<B", os.read(fd_read, 1))[0]
        foff_efh += 4

        if eh_frame_hdr.eh_frame_ptr_enc == DW_ENC.DW_EH_PE_pcrel | DW_ENC.DW_EH_PE_sdata4:
            eh_frame_hdr.eh_frame_ptr = unpack("<i", os.read(fd_read, 4))[0] + foff_efh + eh_frame_hdr.addr
            foff_efh += 4
        else:
            print "unsupported eh_frame_ptr_enc", hex(eh_frame_hdr.eh_frame_ptr_enc)
            exit(1)

        if eh_frame_hdr.fde_count_enc == DW_ENC.DW_EH_PE_udata4:
            eh_frame_hdr.fde_count_offset = os.lseek(fd_read, 0, os.SEEK_CUR)
            eh_frame_hdr.fde_count = unpack("<I", os.read(fd_read, 4))[0]
            foff_efh += 4
        else:
            print "unsupported fde_count_enc", hex(eh_frame_hdr.fde_count_enc)
            exit(1)

        for index in xrange(0, eh_frame_hdr.fde_count):
            assert eh_frame_hdr.table_enc == DW_ENC.DW_EH_PE_datarel | DW_ENC.DW_EH_PE_sdata4
            entry = EH_FRAME_HDR.entry()
            entry.fde_init_loc = unpack("<i", os.read(fd_read, 4))[0] + eh_frame_hdr.addr
            foff = os.lseek(fd_read, 0, os.SEEK_CUR) - 4
            entry.fde_data_offset = unpack("<i", os.read(fd_read, 4))[0]
            self.fde_table.append([foff, entry.fde_init_loc, entry.fde_data_offset])

            foff_efh += 8
            eh_frame_hdr.table.append(entry)

        #eh_frame_hdr.printit()

        os.close(fd_read)

        if patch == True:
            self.patch_eh_frame_hdr(mytext_base, eh_frame_hdr, new_obj_name, binname)

    def patch_eh_frame_hdr(self, mytext_base, eh_frame_hdr, new_obj_name, binname):
        # let's change init_locs to the new text location
        fd_write = os.open(binname, os.O_WRONLY)
        fd_read = os.open(binname, os.O_RDONLY)
        print "\tlet's update .eh_frame_hdr"

        index = write_index = 0
        while index < len(self.fde_table):
            init_loc = self.fde_table[index][1]
            label = "L_" + hex(init_loc)
            label_offset = self.find_label_offset(new_obj_name, label)
            if label_offset != None:
                write_index += 1
            index += 1

        #print "index is", index, "write_index is", write_index
        effective_fde_count = write_index

        cur_foff = self.fde_table[write_index][0]  

        # let's calculate the new address for .eh_frame
        if self.is_eh_frame_hdr_after_eh_frame == False:
            self.new_eh_frame_foff = myround(cur_foff, self.eh_frame_align)
        else:
            self.new_eh_frame_foff = self.old_eh_frame_foff
        self.eh_frame_shift_offset = self.old_eh_frame_foff - self.new_eh_frame_foff
        self.new_eh_frame_addr = self.old_eh_frame_addr - self.eh_frame_shift_offset

        # let's calculate the new address for .gcc_except_table
        if self.has_get:
            if self.is_eh_frame_hdr_after_eh_frame == False:
                self.new_get_foff = myround(self.new_eh_frame_foff + self.eh_frame_size, self.get_align)
            else:
                self.new_get_foff = myround(cur_foff, self.get_align)
            self.get_shift_offset = self.old_get_foff - self.new_get_foff
            self.new_get_addr = self.old_get_addr - self.get_shift_offset

        index = write_index = 0
        while index < len(self.fde_table):
            init_loc = self.fde_table[index][1]
            fde_data_offset = self.fde_table[index][2]
            label = "L_" + hex(init_loc)
            label_offset = self.find_label_offset(new_obj_name, label)
            if label_offset != None:
                new_addr = label_offset + mytext_base
                new_offset = new_addr - eh_frame_hdr.addr
                file_offset = self.fde_table[write_index][0]
                os.lseek(fd_write, file_offset, os.SEEK_SET)
                os.write(fd_write, pack("<i", new_offset))
                os.write(fd_write, pack("<i", fde_data_offset - self.eh_frame_shift_offset))
                #print "\t", hex(init_loc), "->", hex(new_addr)
                write_index += 1
            index += 1

        # update the fde_count
        if eh_frame_hdr.fde_count_enc == DW_ENC.DW_EH_PE_udata4:
            os.lseek(fd_write, eh_frame_hdr.fde_count_offset, os.SEEK_SET)
            os.write(fd_write, pack("<I", effective_fde_count))
        else:
            print "unsupported fde_count_enc", hex(eh_frame_hdr.fde_count_enc)
            exit(1)

        self.elf_frame_hdr_less += ((len(self.fde_table) - effective_fde_count) * 8)

        # update the size info of .eh_frame_hdr
        eh_frame_hdr_size = self.get_section_info(binname, ".eh_frame_hdr", "size")
        new_eh_frame_hdr_size = eh_frame_hdr_size - self.elf_frame_hdr_less
        self.modify_section_info(binname, ".eh_frame_hdr", "size", new_eh_frame_hdr_size)
        self.modify_phdr_info(binname, PHDR.PT_GNU_EH_FRAME, PHDR.p_filesz_offset, new_eh_frame_hdr_size)
        self.modify_phdr_info(binname, PHDR.PT_GNU_EH_FRAME, PHDR.p_memsz_offset, new_eh_frame_hdr_size)

        # now move the .eh_frame section
        os.lseek(fd_read, self.old_eh_frame_foff, os.SEEK_SET)
        buf = os.read(fd_read, self.eh_frame_size)
        os.lseek(fd_write, self.new_eh_frame_foff, os.SEEK_SET)
        os.write(fd_write, buf)

        self.modify_section_info(binname, ".eh_frame", "offset", self.new_eh_frame_foff)
        self.modify_section_info(binname, ".eh_frame", "addr", self.new_eh_frame_addr)

        print "eh_frame_align", hex(self.eh_frame_align)
        print "old_eh_frame_foff", hex(self.old_eh_frame_foff)
        print "new_eh_frame_foff", hex(self.new_eh_frame_foff)
        print "old_eh_frame_addr", hex(self.old_eh_frame_addr)
        print "new_eh_frame_addr", hex(self.new_eh_frame_addr)

        os.close(fd_write)
        os.close(fd_read)
        return

    def analyze_eh_frame(self, binname, new_obj_name, mytext_base, patch=True):
        if patch == True:
            assert self.eh_frame_shift_offset != None
        
        self.new_eh_frame_foff = self.get_section_info(binname, ".eh_frame", "offset")
        self.new_eh_frame_addr = self.get_section_info(binname, ".eh_frame", "addr")
        self.eh_frame_size = self.get_section_info(binname, ".eh_frame", "size")
        fd = os.open(binname, os.O_RDWR)
        os.lseek(fd, self.new_eh_frame_foff, os.SEEK_SET)

        print "eh_frame_size", hex(self.eh_frame_size)
        foff_ef = 0
        while foff_ef < self.eh_frame_size:
            next_CIE_length, next_CIE_id = self.get_next_header(fd)

            if next_CIE_length == 0: # the end
                break

            if next_CIE_id == 0:
                # a CIE entry
                if foff_ef in self.foff_ef2cie:
                    #self.foff_ef2cie[foff_ef].printit()
                    pass
                else:
                    cie = self.get_next_CIE(fd, next_CIE_length, next_CIE_id, foff_ef, 
                            new_obj_name, mytext_base, patch)
                    self.foff_ef2cie[foff_ef] = cie
                    #cie.printit() 
            else:
                # a FDE entry
                fde = self.get_next_FDE(fd, next_CIE_length, next_CIE_id, foff_ef,
                        binname, new_obj_name, mytext_base, patch)
                #fde.printit()

            foff_ef += (next_CIE_length + CIE.length_size)

        if patch == True and False:
            # now move the .gcc_except_table section
            if self.has_get == True:
                os.lseek(fd, self.old_get_foff, os.SEEK_SET)
                buf = os.read(fd, self.old_get_size)
                os.lseek(fd, self.new_get_foff, os.SEEK_SET)
                os.write(fd, buf)
                self.modify_section_info(binname, ".gcc_except_table", "offset", self.new_get_foff)
                self.modify_section_info(binname, ".gcc_except_table", "addr", self.new_get_addr)

        os.close(fd)

    def get_next_header(self, fd):
        length = unpack(pfmt(CIE.length_size), os.read(fd, CIE.length_size))[0]
        if length == 0xffffffff:
            print "a 64-bit DWARF format, does not support yet"
            exit(1)
        if length == 0: # enough! you got too much
            return 0, 0
        id = unpack(pfmt(CIE.cie_id_size), os.read(fd, CIE.cie_id_size))[0]
        return length, id

    def get_next_CIE(self, fd, CIE_length, CIE_id, offset, new_obj_name, mytext_base,
            patch):
        cie = CIE()
        cie.length = CIE_length
        cie.cie_id = CIE_id
        cie.foff_ef = offset

        # the length excluces itself
        has_read_bytes = CIE.cie_id_size
        cie.version = unpack(pfmt(CIE.version_size), os.read(fd, CIE.version_size))[0]
        has_read_bytes += CIE.version_size
        cie.aug, nbytes = self.get_null_ended_string(fd)
        has_read_bytes += nbytes
        cie.code_align_fac, nbytes = self.read_uleb128(fd)
        has_read_bytes += nbytes
        cie.data_align_fac, nbytes = self.read_sleb128(fd)
        has_read_bytes += nbytes
        cie.ret_addr_reg, nbytes = self.read_uleb128(fd)
        has_read_bytes += nbytes
        if cie.aug.startswith('z'):
            cie.aug_data_len, nbytes = self.read_uleb128(fd)
            has_read_bytes += nbytes
            cie.aug_data_foff = os.lseek(fd, 0, os.SEEK_CUR)
            cie.aug_data = os.read(fd, cie.aug_data_len)
            has_read_bytes += cie.aug_data_len
        cie.init_instrs = os.read(fd, CIE_length - has_read_bytes)

        # parse the aug data
        if cie.aug_data_len == None or cie.aug_data_len == 0 or \
                cie.aug == None or cie.aug[0] != 'z':
            return cie

        foff_aug_data = 0
        for index in xrange(1, len(cie.aug)):
            byte = cie.aug[index]
            if byte == 'R':
                cie.fde_encoding = unpack("<B", cie.aug_data[foff_aug_data])[0]
                foff_aug_data += 1
            elif byte == 'L':
                cie.lsda_encoding = unpack("<B", cie.aug_data[foff_aug_data])[0]
                foff_aug_data += 1
            elif byte == 'P':
                cie.personality_encoding = unpack("<B", cie.aug_data[foff_aug_data])[0]
                foff_aug_data += 1
                if cie.personality_encoding == DW_ENC.DW_EH_PE_udata4 :
                    cie.personality = unpack("<I", cie.aug_data[foff_aug_data : foff_aug_data + 4])[0]

                    # patch personality
                    if patch == True:
                        cur_foff = os.lseek(fd, 0, os.SEEK_CUR)
                        label = "L_" + hex(cie.personality)
                        label_offset = self.find_label_offset(new_obj_name, label)
                        if label_offset != None:
                            label_new_addr = mytext_base + label_offset
                            os.lseek(fd, cie.aug_data_foff + foff_aug_data, os.SEEK_SET)
                            os.write(fd, pack("<I", label_new_addr))
                        os.lseek(fd, cur_foff, os.SEEK_SET)

                    foff_aug_data += 4
                else:
                    print "unsupported (not yet) encoding for personality encoding"
                    exit(1)
            elif byte == 'S':
                cie.is_signal_frame = True

        return cie

    def get_next_FDE(self, fd, FDE_length, cie_foff_id, foff_ef, binname,
            new_obj_name, mytext_base, patch):

        # we just finished reading ID, and now we are at init location (pc_begin)
        pc_begin_foff_ef = cur_foff_ef = foff_ef + FDE.length_size + FDE.fde_id_size
        pc_begin_addr = cur_addr = self.old_eh_frame_addr + cur_foff_ef

        fde = FDE()
        fde.length = FDE_length
        fde.cie_foff_id = cie_foff_id
        fde.foff_ef = foff_ef

        # find corresponding CIE first
        cie = None
        cie_foff_ef = foff_ef + FDE.length_size - fde.cie_foff_id
        if cie_foff_ef in self.foff_ef2cie:
            cie = self.foff_ef2cie[cie_foff_ef]
        else:
            os.lseek(fd, self.old_eh_frame_foff + cie_foff_ef, os.SEEK_SET)
            cie_length, cie_id = self.get_next_header(fd)
            cie = self.get_next_CIE(fd, cie_length, cie_id, cie_foff_ef,
                    new_obj_name, mytext_base, patch)
            self.foff_ef2cie[cie_foff_ef] = cie
            # restore the file offset
            os.lseek(fd, self.old_eh_frame_foff + cur_foff_ef, os.SEEK_SET)

        # the len#gth excludes itself
        has_read_bytes = FDE.fde_id_size

        encoding = cie.fde_encoding
        assert encoding == DW_ENC.DW_EH_PE_sdata4 | DW_ENC.DW_EH_PE_pcrel
        if encoding == DW_ENC.DW_EH_PE_sdata4 | DW_ENC.DW_EH_PE_pcrel: 
            fde.pc_begin = unpack("<i", os.read(fd, 4))[0] + pc_begin_addr
            pc_len = unpack("<i", os.read(fd, 4))[0]
            fde.pc_end = fde.pc_begin + pc_len

            # change the address to new text section, if required to patch
            label = "L_" + hex(fde.pc_begin)
            label_offset = None
            if patch == True:
                label_offset = self.find_label_offset(new_obj_name, label)
            # the function entry has to be executed ever
            if patch == True and label_offset != None:
                new_pc_begin = self.get_new_addr(new_obj_name, mytext_base, fde.pc_begin)
                new_pc_end = self.get_new_addr(new_obj_name, mytext_base, fde.pc_end)

                #if new_pc_begin == mytext_base:
                #    new_pc_end = new_pc_begin + fde.pc_end - fde.pc_begin
                #print "----------", hex(fde.pc_begin), "--->", hex(new_pc_begin)
                #print "----------", hex(fde.pc_end), "--->", hex(new_pc_end)

                os.lseek(fd, -8, os.SEEK_CUR)
                os.write(fd, pack("<i", new_pc_begin - (pc_begin_addr - self.eh_frame_shift_offset)))
                os.write(fd, pack("<i", new_pc_end - new_pc_begin))

            has_read_bytes += 8
        else:
            print "cannot handle this encoding of fde.pc_begin:", hex(encoding)

        fde.aug_data_len, nbytes = self.read_uleb128(fd)
        has_read_bytes += nbytes
        fde.aug_data = os.read(fd, fde.aug_data_len)
        has_read_bytes += fde.aug_data_len

        if fde.aug_data_len != 0 and cie.lsda_encoding != None:
            # right, this is a LSDA pointer (address) to .gcc_except_table
            if cie.lsda_encoding == DW_ENC.DW_EH_PE_udata4:
                fde.LSDA_pointer = unpack("<i", fde.aug_data)[0]
                #print "lsda_pointer", hex(fde.LSDA_pointer)
                fde.lsda, acc_extra_bytes = self.get_next_LSDA(binname, fde.LSDA_pointer, 
                        fde.pc_begin, new_obj_name, mytext_base, patch)
                if patch == True:
                    # change the lsda pointer to the new .gcc_except_table section
                    new_lsda_pointer = fde.LSDA_pointer - self.get_shift_offset + acc_extra_bytes
                    #print "---->", hex(new_lsda_pointer)
                    os.lseek(fd, -fde.aug_data_len, os.SEEK_CUR)
                    os.write(fd, pack("<i", new_lsda_pointer))
                    os.lseek(fd, fde.aug_data_len - 4, os.SEEK_CUR)
            else:
                print "unsupported encoding of LSDA_pointer 0x%lx" % cie.lsda_encoding
                exit(1)

        fde.cfi = os.read(fd, fde.length - has_read_bytes)

        return fde

    def get_next_LSDA(self, binname, lsda_addr, func_begin, new_obj_name,
            mytext_base, patch):
        fd_read = os.open(binname, os.O_RDWR)
        lsda_foff_get = lsda_addr - self.old_get_addr
        orig_foff = os.lseek(fd_read, self.old_get_foff + lsda_foff_get, os.SEEK_SET)
        
        lsda = LSDA()
        lsda.func_begin = func_begin

    
        #print "orig_foff", hex(orig_foff)
        # lpstart encoding, mostly omitted
        lsda.lpstart_encoding = unpack("<B", os.read(fd_read, 1))[0] # will not change
        if lsda.lpstart_encoding != DW_ENC.DW_EH_PE_omit:
            print "hmm, seems the lpstart in encoded here, please handle"
            exit(1)
        else:
            lsda.LPStart = lsda.func_begin
        # encoding of type table entries
        lsda.ttable_entry_encoding = unpack("<B", os.read(fd_read, 1))[0] # will not change
        #print "table entry encoding", hex(lsda.ttable_entry_encoding)
        if lsda.ttable_entry_encoding != DW_ENC.DW_EH_PE_omit:
            lsda.ttable_foff_to, nbytes = self.read_uleb128(fd_read) # may change
            cur_foff = os.lseek(fd_read, 0, os.SEEK_CUR)
            lsda.ttable_foff = lsda.ttable_foff_to + cur_foff

        # encoding of call-site table entries
        lsda.cstable_entry_encoding = unpack("<B", os.read(fd_read, 1))[0] # will not change
        # size of call-site table
        #print "cs table entry encoding", hex(lsda.cstable_entry_encoding)
        lsda.cstable_size, nbytes = self.read_uleb128(fd_read)
        #print "cstable size", hex(lsda.cstable_size)

        max_aentry_foff_atable = 0

        # immediately followed by the call-site table
        foff_cstable = 0
        while foff_cstable < lsda.cstable_size:
            if lsda.cstable_entry_encoding == DW_ENC.DW_EH_PE_uleb128:
                cs_entry = LSDA.cstable_entry()
                cs_entry.cs_start, nbytes1 = self.read_uleb128(fd_read)
                #print "cs_start", (cs_entry.cs_start)
                cs_entry.cs_len, nbytes2 = self.read_uleb128(fd_read)
                #print "cs_len", (cs_entry.cs_len)
                cs_entry.cs_lp, nbytes3 = self.read_uleb128(fd_read)
                #print "cs_lp", (cs_entry.cs_lp)

                new_func_begin = 0
                new_cs_entry = None
                if patch == True:
                    new_func_begin = self.get_new_addr(new_obj_name, mytext_base, lsda.func_begin)
                if patch == True and new_func_begin != None:
                    start_pc = lsda.func_begin + cs_entry.cs_start
                    new_start_pc = self.get_new_addr(new_obj_name, mytext_base, start_pc)
                    end_pc = start_pc + cs_entry.cs_len
                    new_end_pc = self.get_new_addr(new_obj_name, mytext_base, end_pc)
                    lp_pc = lsda.LPStart + cs_entry.cs_lp
                    new_lp_pc = self.get_new_addr(new_obj_name, mytext_base, lp_pc)
                    new_lp_start = self.get_new_addr(new_obj_name, mytext_base, lsda.LPStart)
                    #print "func_begin", hex(func_begin), "--->", hex(new_func_begin)
                    #print "start_pc", hex(start_pc), "--->", hex(new_start_pc)
                    #print "end_pc", hex(end_pc), "--->", hex(new_end_pc)
                    #print "lp_pc", hex(lp_pc), "--->", hex(new_lp_pc)
                    assert (new_start_pc != None and new_end_pc != None and new_lp_pc != None)
                    # write them into memory
                    new_start = new_start_pc - new_func_begin
                    new_len = new_end_pc - new_start_pc
                    new_lp = new_lp_pc - new_lp_start

                    os.lseek(fd_read, -(nbytes1 + nbytes2 + nbytes3), os.SEEK_CUR)
                    #print "cs_start is changed:", hex(cs_entry.cs_start), nbytes1, "--->", hex(new_start)
                    self.write_uleb128(fd_read, new_start, nbytes1)
                    nothing, more = self.get_uleb128_encoding(new_start, nbytes1)
                    lsda.extra_bytes += more

                    #print "cs_len is changed:", hex(cs_entry.cs_len), nbytes2, "--->", hex(new_len)
                    self.write_uleb128(fd_read, new_len, nbytes2)
                    nothing, more = self.get_uleb128_encoding(new_len, nbytes2)
                    lsda.extra_bytes += more

                    #print "cs_lp is changed:", hex(cs_entry.cs_lp), nbytes3, "--->", hex(new_lp)
                    self.write_uleb128(fd_read, new_lp, nbytes3)
                    nothing, more = self.get_uleb128_encoding(new_lp, nbytes3)
                    lsda.extra_bytes += more

                    new_cs_entry = LSDA.cstable_entry()
                    new_cs_entry.cs_start = new_start
                    new_cs_entry.cs_len = new_len
                    new_cs_entry.cs_lp = new_lp

                cs_entry.cs_action, nbytes4 = self.read_uleb128(fd_read)
                #print "cs_action", cs_entry.cs_action
                if cs_entry.cs_action > max_aentry_foff_atable:
                    max_aentry_foff_atable = cs_entry.cs_action

                if patch == True:
                    new_cs_entry.cs_action = cs_entry.cs_action
                    lsda.new_cstable.append(new_cs_entry)
                lsda.cstable.append(cs_entry)

                foff_cstable += (nbytes1 + nbytes2 + nbytes3 + nbytes4)
                #print "foffset_cstable", hex(foff_cstable)
            else:
                print "cstable entry encoding by what ?!", hex(lsda.cstable_entry_encoding)
                exit(1)

        lsda.new_cstable_size = lsda.cstable_size + lsda.extra_bytes
        lsda.new_ttable_foff_to = lsda.ttable_foff_to + lsda.extra_bytes

        atable_foff = os.lseek(fd_read, 0, os.SEEK_CUR)

        max_ttable_index = 0
        min_ttable_offset = 0
        foff_atable = 0
        # then followed by the action table
        if max_aentry_foff_atable == 0:
            pass
            #print "there is no action table"
        else:
            #print "max_aentry_foff_atable", hex(max_aentry_foff_atable)
            while foff_atable < max_aentry_foff_atable:
                a_entry = LSDA.atable_entry()
                a_entry.ar_filter, nbytes1 = self.read_sleb128(fd_read)
                a_entry.ar_disp, nbytes2 = self.read_sleb128(fd_read)

                if max_ttable_index < a_entry.ar_filter:
                    max_ttable_index = a_entry.ar_filter
                if min_ttable_offset > a_entry.ar_filter:
                    min_ttable_offset = a_entry.ar_filter

                #a_entry.printit()
                lsda.atable.append(a_entry)
                foff_atable += (nbytes1 + nbytes2)

        if lsda.ttable_foff_to == -1:
            pass 
            #print "there is no type table"
        else:
            if lsda.ttable_entry_encoding == DW_ENC.DW_EH_PE_udata4:
                #print "lsda.ttable_foff is", hex( lsda.ttable_foff)
                #print "max_ttable_index", max_ttable_index
                os.lseek(fd_read, lsda.ttable_foff - 4 * max_ttable_index, os.SEEK_SET)
                lsda.ttable_max_index = max_ttable_index
                lsda.ttable_min_offset = min_ttable_offset
                for index in xrange(0, max_ttable_index):
                    typeinfo = unpack("<I", os.read(fd_read, 4))[0]
                    lsda.ttable_neg.append([max_ttable_index - index, typeinfo])
            else:
                print "unsupported ttable_entry_encoding", hex(lsda.ttable_entry_encoding)
                assert False
            
            #print "min_ttable_offset", min_ttable_offset
            if min_ttable_offset != None and min_ttable_offset < 0:
                min_ttable_offset = -min_ttable_offset
                min_ttable_offset -= 1
                lsda.ttable_min_offset = min_ttable_offset
                ttable_offset = 0
                while ttable_offset <= min_ttable_offset:
                    ttable_index = -1
                    lsda.ttable_pos.append([])
                    while ttable_index != 0:
                        ttable_index, nbytes = self.read_uleb128(fd_read)
                        lsda.ttable_pos[-1].append(ttable_index)
                        ttable_offset += nbytes

        last_foff = os.lseek(fd_read, 0, os.SEEK_CUR)

        if patch == True:
            fd_write = os.open(binname, os.O_WRONLY)
            #print "lsda.acc_extra_bytes", LSDA.acc_extra_bytes
            new_orig_foff = orig_foff - self.get_shift_offset + LSDA.acc_extra_bytes
            start = os.lseek(fd_write, new_orig_foff, os.SEEK_SET)
            #print "new start", hex(start)

            if lsda.extra_bytes == 0:
                # good, we do not have to shift

                # get a copy of the original LSDA
                size = last_foff - orig_foff
                os.lseek(fd_read, orig_foff, os.SEEK_SET)
                buf = os.read(fd_read, size)

                # copy it to the new location
                os.write(fd_write, buf)
            else:
                # it is a little bit tough now
                assert lsda.lpstart_encoding == DW_ENC.DW_EH_PE_omit
                os.write(fd_write, pack("<B", lsda.lpstart_encoding))
                os.write(fd_write, pack("<B", lsda.ttable_entry_encoding))
                if lsda.ttable_entry_encoding != DW_ENC.DW_EH_PE_omit:
                    #print "here"
                    lsda.extra_bytes += self.write_uleb128(fd_write, lsda.new_ttable_foff_to)
                os.write(fd_write, pack("<B", lsda.cstable_entry_encoding))
                lsda.extra_bytes += self.write_uleb128(fd_write, lsda.new_cstable_size)
                assert lsda.cstable_entry_encoding == DW_ENC.DW_EH_PE_uleb128
                for cs_entry in lsda.new_cstable:
                    #print "cs_entry.cs_start", cs_entry.cs_start
                    #print "cs_entry.cs_len", cs_entry.cs_len
                    #print "cs_entry.cs_lp", cs_entry.cs_lp
                    #print "cs_entry.cs_action", cs_entry.cs_action
                    self.write_uleb128(fd_write, cs_entry.cs_start)
                    self.write_uleb128(fd_write, cs_entry.cs_len)
                    self.write_uleb128(fd_write, cs_entry.cs_lp)
                    assert cs_entry.cs_action != 32767
                    self.write_uleb128(fd_write, cs_entry.cs_action)
                os.lseek(fd_read, atable_foff, os.SEEK_SET)
                buf = os.read(fd_read, last_foff - atable_foff)
                os.write(fd_write, buf)
                end = os.lseek(fd_write, 0, os.SEEK_CUR)

                #print "last write end", hex(end)

            os.close(fd_write)

        old_acc_extra_bytes = LSDA.acc_extra_bytes
        LSDA.acc_extra_bytes += lsda.extra_bytes
        #print "lsda.acc_extra_bytes", LSDA.acc_extra_bytes
        os.close(fd_read)
        return lsda, old_acc_extra_bytes

    def get_new_addr(self, new_obj_name, mytext_base, old_addr):
        label = "L_" + hex(old_addr)
        label_offset = self.find_label_offset(new_obj_name, label)
        new_addr = None 
        if label_offset != None:
            new_addr = label_offset + mytext_base
        else:
            label_offset = self.find_next_offset(new_obj_name, label)
            #print "find next label:", label, "--->", new_label, hex(label_offset)
            if label_offset != None:
                new_addr = label_offset + mytext_base
        return new_addr

    def get_null_ended_string(self, fd):
        size = 0
        while True:
            byte = unpack(pfmt(1), os.read(fd, 1))[0]
            size += 1
            if byte == 0:
                os.lseek(fd, -size, os.SEEK_CUR)
                return os.read(fd, size), size
    
    def write_uleb128(self, fd, value, length=0):
        #print "write_uleb128(value=" + hex(value) + ", expected_length=" + str(length) + ")"
        # write the given value into the file
        # length means the expected length of the leb128 string
        array, more = self.get_uleb128_encoding(value, length)
        os.write(fd, pack("<%uB" % len(array), *array))
        return more

    def get_uleb128_encoding(self, value, length=0):
        # try to encoding the given value to uleb128
        array = []
        while True:
            byte = value & 0x7f
            value = value >> 7
            if value == 0:
                array.append(byte)
                break
            else:
                byte = byte | 0x80
                array.append(byte)

        if length == 0:
            return array, 0
    
        #print map(hex, array)
        array_len = len(array)
        if array_len < length:
            self.uleb128_less += (length - array_len)
            # pad it with some 0s
            index = array_len - 1
            array[index] |= 0x80
            index += 1
            while index < length - 1:
                array.append(0x80)
                index += 1
            array.append(0)
    
        if array_len <= length:
            #print "array len is", len(array), "==", length
            return array, 0
        else:
            #print "too large uleb128"
            self.uleb128_more += (array_len - length)
            # so we still write part of it into file, to maintain the correct offset
            short_array = array[0:length]
            return short_array, array_len - length
    
    def read_uleb128(self, fd):
        value = 0
        size = 0
        while True:
            byte = unpack("<B", os.read(fd, 1))[0]
            size += 1
            #print hex(byte),
            if (byte & 0x80) == 0:
                #byte = (byte & 0x7f)
                value += (byte << ((size - 1) * 7))
                #print value
                assert value != 32767
                return value, size
            elif size < 5:
                byte = (byte & 0x7f)
                value += (byte << ((size - 1) * 7))
            else:
                #print size
                print "seems a broken leb128"
                exit(1)
    
    def read_sleb128(self, fd):
        value = 0
        size = 0
        while True:
            byte = unpack("<B", os.read(fd, 1))[0]
            size += 1
            if (byte & 0x80) == 0:
                sign = (byte & 0x40)
                byte = (byte & 0x3f)
                value += (byte << ((size - 1) * 7))
                if sign:
                    value = ~(value - 1) & ((1 << (size * 7 -1)) - 1)
                    value = -value
                #print value
                return value, size
            elif size < 5:
                byte = (byte & 0x7f)
                value += (byte << ((size - 1) * 7))
            else:
                print "seems a broken leb128"
                exit(1)

def myround(x, base=5):
    return int(base * round(float(x)/base))

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('binfile', nargs='?');
    parser.add_argument('-exec_range', action="store_true")
    args = parser.parse_args()

    binname = args.binfile;
    eb = elf_basic();

    if(args.exec_range):
        eb.get_exec_memory_range(binname);

if __name__ == "__main__":
    main()
