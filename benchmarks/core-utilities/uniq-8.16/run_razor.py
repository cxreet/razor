#!/usr/bin/python
from __future__ import print_function
import os, subprocess, sys

DRRUN = '../../../tracers/dynamorio/bin64/drrun'
CLIENT = './logs/libcbr_indcall.so'

def execute(cmd):
    print('running ', cmd)
    p = subprocess.Popen(cmd, shell=True)
    p.communicate()

def train_run(arg1, arg2):
    BIN = './uniq.orig'
    cmd = BIN + ' ' + arg1 + ' ' + arg2
    cmd = DRRUN + ' -c ' + CLIENT + ' -- ' + cmd  + ' > tmp.out'
    execute(cmd)

def test_run(arg1, arg2):
    BIN = './uniq.orig_temp/uniq.orig.debloated'
    cmd = BIN + ' ' + arg1 + ' ' + arg2 + ' > tmp.out'
    execute(cmd)


def train():
    d = 'train/'
    for fname in os.listdir(d):
        train_run("", d + fname)
        train_run("-c", d + fname)
        train_run("-d", d + fname)
        train_run("-u", d + fname)
        train_run("-i", d + fname)
        train_run("-f 5", d + fname)
        train_run("-s 10", d + fname)
        train_run("-w 10", d + fname)
    return

def test():
    d = 'test/'
    for fname in os.listdir(d):
        test_run("", d + fname)
        test_run("-c", d + fname)
        test_run("-d", d + fname)
        test_run("-u", d + fname)
        test_run("-i", d + fname)
        test_run("-f 5", d + fname)
        test_run("-s 10", d + fname)
        test_run("-w 10", d + fname)
    return


def debloat(logs_dir, prog_name):
    execute("""python ../../../stitcher/src/merge_log.py %s %s""" % (logs_dir, prog_name))
    execute("""mv %s/%s-trace.log ./""" % (logs_dir, prog_name))
    execute("""python ../../../stitcher/src/instr_dumper.py ./%s-trace.log ./%s.orig ./instr.s""" % (prog_name, prog_name))
    execute("""python ../../../stitcher/src/find_symbols.py ./%s.orig ./instr.s """ % (prog_name))
    execute("""python ../../../stitcher/src/stitcher.py ./%s-trace.log ./%s.orig ./%s.s ./callbacks.txt""" % (prog_name, prog_name, prog_name))
    execute("""python ../../../stitcher/src/merge_bin.py %s.orig %s.s""" % (prog_name, prog_name))

def extend_debloat(prog_name, heuristic_level):
    execute("""python ../../../stitcher/src/heuristic/disasm.py ./%s.orig ./%s.orig.asm """ % (prog_name, prog_name))
    execute("""python ../../../stitcher/src/heuristic/find_more_paths.py ./%s.orig.asm ./%s-trace.log ./%s-extended.log %d""" % (prog_name, prog_name, prog_name, heuristic_level))
    execute("""python ../../../stitcher/src/instr_dumper.py ./%s-extended.log ./%s.orig ./instr.s""" % (prog_name, prog_name))
    execute("""python ../../../stitcher/src/find_symbols.py ./%s.orig ./instr.s""" % (prog_name))
    execute("""python ../../../stitcher/src/stitcher.py ./%s-extended.log ./%s.orig ./%s.s ./callbacks.txt""" % (prog_name, prog_name, prog_name))
    execute("""python ../../../stitcher/src/merge_bin.py %s.orig %s.s""" % (prog_name, prog_name))

def clean():
    for fname in os.listdir('./'):
        if fname == "run_razor.py":
            continue
        
        if fname.startswith('test') or fname.startswith('train'):
            continue
        
        if fname == "uniq.orig":
            continue

        execute('rm -rf ./' + fname)

def usage():
    print('python run_razor.py clean|train|test|debloat|extend_debloat\n')
    sys.exit(1)

def main():
    if len(sys.argv) != 2 and len(sys.argv) != 3:
        usage()
    
    if not os.path.exists("./logs"):
        cmd = "mkdir -p ./logs"
        execute(cmd)

        cmd = "cp ../../../tracers/bin/libcbr_indcall.so ./logs/"
        execute(cmd)

    if sys.argv[1] == 'train':
        train()
    
    elif sys.argv[1] == 'test':
        test()

    elif sys.argv[1] == 'debloat':
        debloat('logs', 'uniq')

    elif sys.argv[1] == 'extend_debloat':
        if len(sys.argv) != 3:
            print("Please specify heuristic level (i.e., 1 ~ 4).")
            sys.exit(1)
        heuristic_level = int(sys.argv[2])
        extend_debloat('uniq', heuristic_level)

    elif sys.argv[1] == 'clean':
        clean()

    else:
        usage()

if __name__ == '__main__':
    main()
