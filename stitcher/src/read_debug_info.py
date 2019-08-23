#!/usr/bin/env python

from elf_basic import *
import os
import sys

if len(sys.argv) != 2:
    print "Usage: ./read_debug_info.py  bin_file"
    exit(1)



eb =  elf_basic()
eb.initELF(sys.argv[1])

eb.analyze_eh_frame_hdr(sys.argv[1], "abc", 0, False)
eb.analyze_eh_frame(sys.argv[1], "abc", 0, False)
