#!/usr/bin/python
from __future__ import print_function
import os, subprocess, sys

DRRUN = '../../../tracers/dynamorio/bin64/drrun'
CLIENT = './logs/libcbr_indcall.so'

def execute(cmd):
    print('running ', cmd)
    p = subprocess.Popen(cmd, shell=True)
    p.communicate()

def train_run(arg):
    BIN = './grep.orig'
    cmd = BIN + ' ' + arg
    cmd = DRRUN + ' -c ' + CLIENT + ' -- ' + cmd
    execute(cmd)

def test_run(arg):
    BIN = './grep.orig_temp/grep.orig.debloated'
    cmd = BIN + ' ' + arg
    execute(cmd)


def train():
    # 19
    train_run( """ "a" ./train1  > log1""")
    train_run( """ -n "si" ./train1  > log1""")
    train_run( """ -o [r][a][n][d]* ./train1  > log1""")
    train_run( """ -v "a" ./train1  > log1""")
    train_run( """ -i "Si" ./train1  > log1""")
    train_run( """ -w "Si" ./train1  > log1""")
    train_run( """ -x "Don't" ./train1  > log1""")
    train_run( """ -E "randomtext*" ./train1  > log1""")
    train_run( """ "ye " ./train1  > log1""")
    train_run( """ "cold" ./train1  > log1""")
    train_run( """ "not exist" ./train1  > log1""")
    train_run( """ ^D  ./train1  > log1""")
    train_run( """ .$  ./train1  > log1""")
    train_run( """ \^  ./train1  > log1""")
    train_run( """ \^$  ./train1  > log1""")
    train_run( """ ^[AEIOU]  ./train1  > log1""")
    train_run( """ ^[^AEIOU]  ./train1  > log1""")
    train_run( """ -E "free[^[:space:]]+"  ./train1  > log1""")
    train_run( """ -E '\b(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?\.)3}(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)'  ./train1  > log1""")
    return

def test():
    #38
    test_run( """ "a" ./test1  > log1""")
    test_run( """ "a" ./test2  > log1""")
    test_run( """ -n "si" ./test1  > log1""")
    test_run( """ -n "si" ./test2  > log1""")
    test_run( """ -o [r][a][n][d]* ./test1  > log1""")
    test_run( """ -o [r][a][n][d]* ./test2  > log1""")
    test_run( """ -v "a" ./test1  > log1""")
    test_run( """ -v "a" ./test2  > log1""")
    test_run( """ -i "Si" ./test1  > log1""")
    test_run( """ -i "Si" ./test2  > log1""")
    test_run( """ -w "Si" ./test1  > log1""")
    test_run( """ -w "Si" ./test2  > log1""")
    test_run( """ -x "Don't" ./test1  > log1""")
    test_run( """ -x "Don't" ./test2  > log1""")
    test_run( """ -E "randomtext*" ./test1  > log1""")
    test_run( """ -E "randomtext*" ./test2  > log1""")
    test_run( """ "ye " ./test1  > log1""")
    test_run( """ "ye " ./test2  > log1""")
    test_run( """ "cold" ./test1  > log1""")
    test_run( """ "cold" ./test2  > log1""")
    test_run( """ "not exist" ./test1  > log1""")
    test_run( """ "not exist" ./test2  > log1""")
    test_run( """ ^D  ./test1  > log1""")
    test_run( """ ^D  ./test2  > log1""")
    test_run( """ .$  ./test1  > log1""")
    test_run( """ .$  ./test2  > log1""")
    test_run( """ \^  ./test1  > log1""")
    test_run( """ \^  ./test2  > log1""")
    test_run( """ \^$  ./test1  > log1""")
    test_run( """ \^$  ./test2  > log1""")
    test_run( """ ^[AEIOU]  ./test1  > log1""")
    test_run( """ ^[AEIOU]  ./test2  > log1""")
    test_run( """ ^[^AEIOU]  ./test1  > log1""")
    test_run( """ ^[^AEIOU]  ./test2  > log1""")
    test_run( """ -E "free[^[:space:]]+"  ./test1  > log1""")
    test_run( """ -E "free[^[:space:]]+"  ./test2  > log1""")
    test_run( """ -E '\b(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?\.)3}(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)'  ./test1  > log1""")
    test_run( """ -E '\b(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?\.)3}(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)'  ./test2  > log1""")
    return

def debloat(logs_dir, prog_name):
    execute("""python ../../../stitcher/src/merge_log.py %s %s""" % (logs_dir, prog_name))
    execute("""mv %s/%s-trace.log ./""" % (logs_dir, prog_name))
    execute("""python ../../../stitcher/src/instr_dumper.py ./%s-trace.log ./%s.orig ./instr.s""" % (prog_name, prog_name))
    execute("""python ../../../stitcher/src/find_symbols.py ./%s.orig ./instr.s > ./callbacks.txt""" % (prog_name))
    execute("""python ../../../stitcher/src/stitcher.py ./%s-trace.log ./%s.orig ./%s.s ./callbacks.txt""" % (prog_name, prog_name, prog_name))
    execute("""python ../../../stitcher/src/merge_bin.py %s.orig %s.s""" % (prog_name, prog_name))

def extend_debloat(prog_name, heuristic_level):
    execute("""python ../../../stitcher/src/heuristic/disasm.py ./%s.orig ./%s.orig.asm """ % (prog_name, prog_name))
    execute("""python ../../../stitcher/src/heuristic/find_more_paths.py ./%s.orig.asm ./%s-trace.log ./%s-extended.log %d""" % (prog_name, prog_name, prog_name, heuristic_level))
    execute("""python ../../../stitcher/src/instr_dumper.py ./%s-extended.log ./%s.orig ./instr.s""" % (prog_name, prog_name))
    execute("""python ../../../stitcher/src/find_symbols.py ./%s.orig ./instr.s > ./callbacks.txt""" % (prog_name))
    execute("""python ../../../stitcher/src/stitcher.py ./%s-extended.log ./%s.orig ./%s.s ./callbacks.txt""" % (prog_name, prog_name, prog_name))
    execute("""python ../../../stitcher/src/merge_bin.py %s.orig %s.s""" % (prog_name, prog_name))

def clean():
    for fname in os.listdir('./'):
        if fname == "run_razor.py":
            continue
        
        if fname.startswith('test') or fname.startswith('train'):
            continue
        
        if fname == "grep.orig":
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
        debloat('logs', 'grep')

    elif sys.argv[1] == 'extend_debloat':
        if len(sys.argv) != 3:
            print("Please specify heuristic level (i.e., 1 ~ 4).")
            sys.exit(1)
        heuristic_level = int(sys.argv[2])
        extend_debloat('grep', heuristic_level)

    elif sys.argv[1] == 'clean':
        clean()

    else:
        usage()

if __name__ == '__main__':
    main()
