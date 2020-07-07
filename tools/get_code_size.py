#!/usr/bin/python
from __future__ import print_function
import os, subprocess, sys
from elftools.elf.elffile import ELFFile
from elftools.elf.sections import NoteSection



def main():
    s = 0

    cmd = 'readelf -Wl {}'.format(sys.argv[1])
    p = subprocess.Popen(cmd, shell=True, stdout=subprocess.PIPE)
    out = p.communicate()[0]

    for line in out.split('\n'):
        line = line.strip()
        if line.startswith('LOAD'):
            tokens = line.split()
            if tokens[-2] == 'E':
                print(line)
                print('size:', int(tokens[-4], 16))
    
    """
    with open(sys.argv[1], 'rb') as f:
        for sect in ELFFile(f).iter_sections():
            flags = sect.header['sh_flags']
            if (flags & 0x4) != 0:
                s += sect.header['sh_size']
                print(sect.name, sect.header['sh_size'])

    print('code size: 0x%x\n' % s)
    """

if __name__ == '__main__':
    main()
