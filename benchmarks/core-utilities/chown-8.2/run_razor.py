#!/usr/bin/python
from __future__ import print_function
import os, subprocess, sys, pwd

DRRUN = '../../../tracers/dynamorio/bin64/drrun'
CLIENT = './logs/libcbr_indcall.so'

def execute(cmd):
    print('running ', cmd)
    p = subprocess.Popen(cmd, shell=True)
    p.communicate()

def train_run(option, reduce_file):
    BIN = './chown.orig'
    username = pwd.getpwuid(os.getuid())[0]
    cmd = BIN + ' ' + option + ' %s:%s ' % (username, username) + reduce_file
    cmd = DRRUN + ' -c ' + CLIENT + ' -- ' + cmd
    execute(cmd)

def test_run(option, reduce_file):
    BIN = './chown.orig_temp/chown.orig.debloated'
    username = pwd.getpwuid(os.getuid())[0]
    cmd = BIN + ' ' + option + ' %s:%s ' % (username, username) + reduce_file
    execute(cmd)

def train():
    execute('touch file1')
    train_run('', 'file1')
    execute('rm -rf file1')

    execute('mkdir -p d1/d1/d1')
    execute('touch d1/d1/d1/file')
    train_run('', 'd1/d1/d1/file')
    execute('rm -rf d1')

    execute('mkdir -p d1/d1/d1')
    execute('touch d1/d1/d1/file')
    train_run('', 'd1')
    execute('rm -rf d1')

    execute('mkdir -p d1/d1/d1')
    execute('touch d1/d1/d1/file')
    train_run('-R', 'd1')
    execute('rm -rf d1')

    execute('touch file1')
    execute('ln -s file1 symfile1')
    train_run('-h', 'file1')
    execute('rm -rf file1 symfile1')

    execute('touch file1')
    execute('ln -s file1 symfile1')
    train_run('-h', 'symfile1')
    execute('rm -rf file1 symfile1')

def test():
    execute('touch .file1')
    test_run('', '.file1')
    execute('rm -rf .file1')

    execute('mkdir -p d1/d1/d1/d1/d1/d1/d1/d1/d1')
    execute('touch    d1/d1/d1/d1/d1/d1/d1/d1/d1/file')
    execute('touch    d1/d1/d1/d1/d1/d1/d1/d1/d1/.file')
    test_run('', 'd1/d1/d1/d1/d1/d1/d1/d1/d1/file')
    test_run('', 'd1/d1/d1/d1/d1/d1/d1/d1/d1/.file')
    execute('rm -rf d1')

    execute('mkdir -p d1/d1/d1/d1/d1/d1/d1/d1/d1')
    execute('touch    d1/d1/d1/d1/d1/d1/d1/d1/d1/file')
    test_run('', 'd1')
    execute('rm -rf d1')

    execute('mkdir -p d1/d1/d1/d1/d1/d1/d1/d1/d1')
    execute('touch    d1/d1/d1/d1/d1/d1/d1/d1/d1/file')
    execute('touch    d1/d1/d1/d1/d1/d1/d1/d1/d1/.file')
    test_run('-R', 'd1')
    execute('rm -rf d1')

    execute('mkdir -p d1/d1/d1/d1/d1/d1/d1/d1/d1')
    execute('touch    d1/d1/d1/d1/d1/d1/d1/d1/d1/file')
    execute('touch    d1/d1/d1/d1/d1/d1/d1/d1/d1/.file')
    test_run('-R', 'd1/d1')
    execute('rm -rf d1')

    execute('mkdir -p d1/d1/d1/d1/d1/d1/d1/d1/d1')
    execute('touch    d1/d1/d1/d1/d1/d1/d1/d1/d1/file')
    execute('touch    d1/d1/d1/d1/d1/d1/d1/d1/d1/.file')
    test_run('-R', 'd1/d1/d1')
    execute('rm -rf d1')

    execute('mkdir -p d1/d1/d1/d1/d1/d1/d1/d1/d1')
    execute('touch    d1/d1/d1/d1/d1/d1/d1/d1/d1/file')
    execute('touch    d1/d1/d1/d1/d1/d1/d1/d1/d1/.file')
    test_run('-R', 'd1/d1/d1/d1')
    execute('rm -rf d1')

    execute('mkdir -p d1/d1/d1/d1/d1/d1/d1/d1/d1')
    execute('touch    d1/d1/d1/d1/d1/d1/d1/d1/d1/file')
    execute('touch    d1/d1/d1/d1/d1/d1/d1/d1/d1/.file')
    test_run('-R', 'd1/d1/d1/d1/d1')
    execute('rm -rf d1')

    execute('mkdir -p d1/d1/d1/d1/d1/d1/d1/d1/d1')
    execute('touch    d1/d1/d1/d1/d1/d1/d1/d1/d1/file')
    execute('touch    d1/d1/d1/d1/d1/d1/d1/d1/d1/.file')
    test_run('-R', 'd1/d1/d1/d1/d1/d1')
    execute('rm -rf d1')

    execute('mkdir -p d1/d1/d1/d1/d1/d1/d1/d1/d1')
    execute('touch    d1/d1/d1/d1/d1/d1/d1/d1/d1/file')
    execute('touch    d1/d1/d1/d1/d1/d1/d1/d1/d1/.file')
    test_run('-R', 'd1/d1/d1/d1/d1/d1/d1')
    execute('rm -rf d1')

    execute('mkdir -p d1/d1/d1/d1/d1/d1/d1/d1/d1')
    execute('touch    d1/d1/d1/d1/d1/d1/d1/d1/d1/file')
    execute('touch    d1/d1/d1/d1/d1/d1/d1/d1/d1/.file')
    test_run('-R', 'd1/d1/d1/d1/d1/d1/d1/d1')
    execute('rm -rf d1')

    execute('mkdir -p d1/d1/d1/d1/d1/d1/d1/d1/d1')
    execute('touch    d1/d1/d1/d1/d1/d1/d1/d1/d1/file')
    execute('touch    d1/d1/d1/d1/d1/d1/d1/d1/d1/.file')
    test_run('-R', 'd1/d1/d1/d1/d1/d1/d1/d1/d1')
    execute('rm -rf d1')


    execute('touch file1')
    execute('ln -s file1 symfile1')
    execute('ln -s file1 symfile2')
    test_run('-h', 'file1')
    execute('rm -rf file1 symfile*')

    execute('touch file1')
    execute('ln -s file1 symfile1')
    execute('ln -s file1 symfile2')
    test_run('-h', 'symfile1')
    execute('rm -rf file1 symfile*')

    execute('touch file1')
    execute('ln -s file1 symfile1')
    execute('ln -s file1 symfile2')
    test_run('-h', 'symfile2')
    execute('rm -rf file1 symfile*')

    execute('touch file1')
    execute('ln -s file1 symfile1')
    execute('ln -s file1 symfile2')
    test_run('-h', 'symfile*')
    execute('rm -rf file1 symfile*')

    return

def debloat(logs_dir, prog_name):
    execute("""python ../../../stitcher/src/merge_log.py %s %s""" % (logs_dir, prog_name))
    execute("""mv %s/%s-trace.log ./""" % (logs_dir, prog_name))
    execute("""python ../../../stitcher/src/instr_dumper.py ./%s-trace.log ./%s.orig ./instr.s""" % (prog_name, prog_name))
    execute("""python ../../../stitcher/src/find_symbols.py ./%s.orig ./instr.s""" % (prog_name))
    execute("""python ../../../stitcher/src/stitcher.py ./%s-trace.log ./%s.orig ./%s.s ./callbacks.txt""" % (prog_name, prog_name, prog_name))
    execute("""python ../../../stitcher/src/merge_bin.py %s.orig %s.s""" % (prog_name, prog_name))

def extend_debloat(prog_name):
    execute("""python ../../../stitcher/src/heuristic/disasm.py ./%s.orig ./%s.orig.asm """ % (prog_name, prog_name))
    execute("""python ../../../stitcher/src/heuristic/find_more_paths.py ./%s.orig.asm ./%s-trace.log ./%s-extended.log""" % (prog_name, prog_name, prog_name))
    execute("""python ../../../stitcher/src/instr_dumper.py ./%s-extended.log ./%s.orig ./instr.s""" % (prog_name, prog_name))
    execute("""python ../../../stitcher/src/find_symbols.py ./%s.orig ./instr.s""" % (prog_name))
    execute("""python ../../../stitcher/src/stitcher.py ./%s-extended.log ./%s.orig ./%s.s ./callbacks.txt""" % (prog_name, prog_name, prog_name))
    execute("""python ../../../stitcher/src/merge_bin.py %s.orig %s.s""" % (prog_name, prog_name))

def clean():
    for fname in os.listdir('./'):
        if fname == "run_razor.py":
            continue
        
        if fname == 'test' or fname == 'train':
            continue

        if fname == "chown.orig":
            continue

        if fname == "README.md":
            continue

        execute('rm -rf ./' + fname)

def usage():
    print('python run_razor.py train|test|debloat|extend_debloat|debloat_patch\n')
    sys.exit(1)

def main():
    if len(sys.argv) != 2:
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
        debloat('logs', 'chown')

    elif sys.argv[1] == 'extend_debloat':
        extend_debloat('chown')

    elif sys.argv[1] == 'clean':
        clean()

    else:
        usage()

if __name__ == '__main__':
    main()
