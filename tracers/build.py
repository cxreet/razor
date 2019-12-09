#!/usr/bin/env python
from __future__ import print_function
import os, subprocess, sys

pwd = os.getcwd()
pin_src = os.path.join(pwd, 'src', 'pin')

def execute(cmd):
    print(cmd)
    p = subprocess.Popen(cmd, shell=True)
    p.communicate()

def build_dynamorio():
    # download dynamorio relsease version 7.0.0 if it doesn't exist
    if not os.path.exists('./dynamorio'):
        cmd = 'wget https://github.com/DynamoRIO/dynamorio/releases/download/release_7.1.0/DynamoRIO-Linux-7.1.0-1.tar.gz'
        execute(cmd)

        cmd = 'tar -xzvf DynamoRIO-Linux-7.1.0-1.tar.gz'
        execute(cmd)

        cmd = 'mv DynamoRIO-Linux-7.1.0-1 dynamorio'
        execute(cmd)

        cmd = 'rm DynamoRIO-Linux-7.1.0-1.tar.gz'
        execute(cmd)

    # create build, bin
    if not os.path.exists('./build'):
        cmd = 'mkdir ./build'
        execute(cmd)
    
    if not os.path.exists('./bin'):
        cmd = 'mkdir ./bin'
        execute(cmd)

    # build
    os.chdir('./build')
    cmd = 'cmake -DDynamoRIO_DIR={}/dynamorio/cmake {}/src/dynamorio'.format(pwd, pwd)
    execute(cmd)
    cmd = 'make'
    execute(cmd)
    cmd = 'mv *.so ../bin'
    execute(cmd)
    os.chdir(pwd)

def build_pin():
    # download pin https://software.intel.com/sites/landingpage/pintool/downloads/pin-3.7-97619-g0d0c92f4f-gcc-linux.tar.gz
    if not os.path.exists('./pin'):
        cmd = 'wget https://software.intel.com/sites/landingpage/pintool/downloads/pin-3.7-97619-g0d0c92f4f-gcc-linux.tar.gz'
        execute(cmd)
    
        cmd = 'tar -xzvf pin-3.7-97619-g0d0c92f4f-gcc-linux.tar.gz'
        execute(cmd)
    
        cmd = 'rm pin-3.7-97619-g0d0c92f4f-gcc-linux.tar.gz'
        execute(cmd)
    
        cmd = 'mv pin-3.7-97619-g0d0c92f4f-gcc-linux pin'
        execute(cmd)

    # create build, bin
    if not os.path.exists('./build'):
        cmd = 'mkdir ./build'
        execute(cmd)
    
    if not os.path.exists('./bin'):
        cmd = 'mkdir ./bin'
        execute(cmd)

    os.chdir(pin_src)
    cmd = 'make PIN_ROOT=../../../pin'
    execute(cmd)
    cmd = 'mv obj-intel64/*.so ../../../bin/' 
    
    os.chdir(pin_src)
    cmd = 'make PIN_ROOT=../../pin'
    execute(cmd)
    cmd = 'mv obj-intel64/*.so ../../bin/' 

    execute(cmd)
    cmd = 'rm -rf obj-intel64'
    execute(cmd)
    os.chdir(pwd)
    
def build_pt():
    # create build, bin
    if not os.path.exists('./build'):
        cmd = 'mkdir ./build'
        execute(cmd)
    
    if not os.path.exists('./bin'):
        cmd = 'mkdir ./bin'
        execute(cmd)

    # download libipt from the official repo
    if not os.path.exists('./pt'):
        #cmd = "git clone git@github.com:01org/pt.git"
    
        cmd = "wget https://github.com/01org/processor-trace/archive/master.zip"
        execute(cmd)
        cmd = "unzip master.zip"
        execute(cmd)
        cmd = "mv libipt-master pt"
        execute(cmd)
        cmd = "rm master.zip"
        execute(cmd)
        
        cmd = "mv pt/script/perf-read-aux.bash pt/script/perf-read-aux.bash.bak"
        execute(cmd)
        cmd = "mv pt/script/perf-read-sideband.bash pt/script/perf-read-sideband.bash.bak"
        execute(cmd)
        cmd = "mv pt/ptxed/src/ptxed.c pt/ptxed/src/ptxed.c.bak"
        execute(cmd)
        cmd = "mv pt/CMakeLists.txt pt/CMakeLists.txt.bak"
        execute(cmd)
        cmd = "mv pt/ptxed/CMakeLists.txt pt/ptxed/CMakeLists.txt.bak"
        execute(cmd)
        cmd = "mv pt/sideband/src/pt_sb_pevent.c pt/sideband/src/pt_sb_pevent.c.bak"
        execute(cmd)
        cmd = "mv pt/sideband/include/libipt-sb.h.in pt/sideband/include/libipt-sb.h.in.bak"
        execute(cmd)
        cmd = "mv pt/sideband/internal/include/pt_sb_session.h pt/sideband/internal/include/pt_sb_session.h.bak"
        execute(cmd)
        cmd = "mv pt/ptdump/src/ptdump.c pt/ptdump/src/ptdump.c.bak"
        execute(cmd)
    
    
        cmd = "ln -s ../../src/pt/perf-read-aux.bash pt/script/perf-read-aux.bash"
        execute(cmd)
        cmd = "ln -s ../../src/pt/perf-read-sideband.bash pt/script/perf-read-sideband.bash"
        execute(cmd)
        cmd = "ln -s ../../../src/pt/ptxed.c pt/ptxed/src/ptxed.c"
        execute(cmd)
        cmd = "ln -s ../src/pt/build.py pt/"
        execute(cmd)
        cmd = "ln -s ../src/pt/CMakeLists.txt pt/"
        execute(cmd)
        cmd = "ln -s ../../src/pt/ptxed-CMakeLists.txt pt/ptxed/CMakeLists.txt"
        execute(cmd)
        cmd = "ln -s ../../../src/pt/pt_sb_pevent.c pt/sideband/src/pt_sb_pevent.c"
        execute(cmd)
        cmd = "ln -s ../../../src/pt/libipt-sb.h.in pt/sideband/include/libipt-sb.h.in"
        execute(cmd)
        cmd = "ln -s ../../../../src/pt/pt_sb_session.h pt/sideband/internal/include/pt_sb_session.h"
        execute(cmd)
        cmd = "ln -s ../../../src/pt/ptdump.c pt/ptdump/src/ptdump.c"
        execute(cmd)

    os.chdir("./pt")
    cmd = "./build.py"
    execute(cmd)
    cmd = "mv build/bin/* ../bin/"
    execute(cmd)
    os.chdir(pwd)

def main():
    print (len(sys.argv))
    if len(sys.argv) == 1:
        build_dynamorio()
        build_pin()
        build_pt()
    elif len(sys.argv) > 1:
        for arg in sys.argv[1:]:
            if arg == 'dynamorio':
                build_dynamorio()
            elif arg == 'pin':
                build_pin()
            elif arg == 'pt':
                build_pt()
            else:
                print ("unexpected target", arg)
                sys.exit(1)
    else:
        print ("Usage: python ./build.py [dynamorio] [pin] [pt]")
        sys.exit(1)


if __name__ == '__main__':
        main()
