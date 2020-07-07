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
    BIN = './mkdir.orig'
    cmd = BIN + ' ' + arg1 + ' ' + arg2
    cmd = DRRUN + ' -c ' + CLIENT + ' -- ' + cmd
    execute(cmd)

def test_run(arg1, arg2):
    BIN = './mkdir.orig_temp/mkdir.orig.debloated'
    cmd = BIN + ' ' + arg1 + ' ' + arg2
    execute(cmd)

def train():
    # 12
    train_run("", "d1")
    execute("""rm -rf d1""")

    train_run("", "d1/d2")
    execute("""rm -rf d1""")

    train_run("-p", "d1/d2")
    train_run("-p", "d1/d3")
    execute("""rm -rf d1""")

    train_run("", "d1")
    train_run("-m 777", "d1/d2")
    execute("""rm -rf d1""")

    train_run("-p -m 777", "d1/d2")
    execute("""rm -rf d1""")

    train_run("-m", "d1")
    execute("""rm -rf d1""")

    train_run("-p -m 555", "d1/d2")
    execute("""rm -rf d1""")

    train_run("-m 644", "d1")
    execute("""rm -rf d1""")

    train_run("-m 610", "d1")
    execute("""rm -rf d1""")

    train_run("-m 777", "d1")
    execute("""rm -rf d1""")

    train_run("-p -m 777", "d1/d2")
    train_run("-p -m 567", "d1/d3")
    execute("""rm -rf d1""")

    train_run("-p", "d1/d2/d3/d4")
    train_run("-m 500", "d1/d2/d3/d5")
    execute("""rm -rf d1""")

    execute("""rm -rf d1  d2 d3""")
    return

def test():
    # 24
    test_run("", "d1/d2/d3")
    execute('rm -rf d1')

    test_run("-p", "d1/d2/d3")
    execute('rm -rf d1')

    test_run("-p -m 567", "d1/d2/d3")
    execute('rm -rf d1')

    test_run("-m 777", "d1/d2")
    execute('rm -rf d1')

    test_run("-p -m 777", "d1/d2/d3")
    execute('rm -rf d1')

    test_run("-p -m 777", "d1/d2/d3")
    test_run("-p -m 500", "d1/d2/d3/d4")
    execute('rm -rf d1')

    test_run("-p -m 555", "d1/d2/d3/d4")
    test_run("-m 644", "d1/d2/d3/d5")
    test_run("-m 610", "d1/d6")
    test_run("-m 777", "d1/d6/d7")
    execute('rm -rf d1')

    test_run("-p -m 777", "d1/d2/d3")
    test_run("-m 555", "d1/d2/d3")
    test_run("-m 644", "d1/d2/d3/d4")
    test_run("-m 610", "d1/d2/d3/d4/d5")
    test_run("-m 777", "d1/d2/d3/d4/d5/d6")
    execute('rm -rf d1')

    test_run("-p -m 777", "d1/d2/d3")
    test_run("-m 555", "d1/d2/d4")
    test_run("-m 644", "d1/d2/d5")
    test_run("-m 610", "d1/d2/d6")
    test_run("-m 777", "d1/d2/d7")
    execute('rm -rf d1')

    test_run("-p", "d1/d2/d3")
    test_run("-p", "d1/d2/d3/d4")
    test_run("-p", "d1/d2/d3/d5")
    test_run("-p", "d1/d2/d3/d5/d6")
    execute("""rm -rf d1""")


    execute("""rm -rf d1  d2 d3""")
    return

def get_traces_for_test(logs_dir, prog_name):
    train_run("", "d1/d2/d3")
    execute('rm -rf d1')

    train_run("-p", "d1/d2/d3")
    execute('rm -rf d1')

    train_run("-p -m 567", "d1/d2/d3")
    execute('rm -rf d1')

    train_run("-m 777", "d1/d2")
    execute('rm -rf d1')

    train_run("-p -m 777", "d1/d2/d3")
    execute('rm -rf d1')

    train_run("-p -m 777", "d1/d2/d3")
    train_run("-p -m 500", "d1/d2/d3/d4")
    execute('rm -rf d1')

    train_run("-p -m 555", "d1/d2/d3/d4")
    train_run("-m 644", "d1/d2/d3/d5")
    train_run("-m 610", "d1/d6")
    train_run("-m 777", "d1/d6/d7")
    execute('rm -rf d1')

    train_run("-p -m 777", "d1/d2/d3")
    train_run("-m 555", "d1/d2/d3")
    train_run("-m 644", "d1/d2/d3/d4")
    train_run("-m 610", "d1/d2/d3/d4/d5")
    train_run("-m 777", "d1/d2/d3/d4/d5/d6")
    execute('rm -rf d1')

    train_run("-p -m 777", "d1/d2/d3")
    train_run("-m 555", "d1/d2/d4")
    train_run("-m 644", "d1/d2/d5")
    train_run("-m 610", "d1/d2/d6")
    train_run("-m 777", "d1/d2/d7")
    execute('rm -rf d1')

    train_run("-p", "d1/d2/d3")
    train_run("-p", "d1/d2/d3/d4")
    train_run("-p", "d1/d2/d3/d5")
    train_run("-p", "d1/d2/d3/d5/d6")
    execute("""rm -rf d1""")

    execute("""rm -rf d1  d2 d3""")

    execute("""python ../../../stitcher/src/merge_log.py %s %s""" % (logs_dir, prog_name))
    execute("""mkdir -p ./backup""")
    execute("""mv %s/%s-trace.log ./backup/""" % (logs_dir, prog_name))


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
        
        if fname.startswith('test') or fname.startswith('train') or fname == "backup":
            continue
        
        if fname == "mkdir.orig" or fname == "mkdir-5.2.1.c.orig.c":
            continue

        execute('rm -rf ./' + fname)

def usage():
    print('python run_razor.py clean|train|test|debloat|extend_debloat|get_test_traces\n')
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
        debloat('logs', 'mkdir')

    elif sys.argv[1] == 'extend_debloat':
        if len(sys.argv) != 3:
            print("Please specify heuristic level (i.e., 1 ~ 4).")
            sys.exit(1)
        heuristic_level = int(sys.argv[2])
        extend_debloat('mkdir', heuristic_level)
    
    elif sys.argv[1] == "get_test_traces":
        get_traces_for_test('logs', 'mkdir')

    elif sys.argv[1] == 'clean':
        clean()

    else:
        usage()

if __name__ == '__main__':
    main()
