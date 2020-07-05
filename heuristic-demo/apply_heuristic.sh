#!/bin/bash

set -ex
python ../stitcher/src/heuristic/disasm.py ./simple ./simple.asm
python ../stitcher/src/heuristic/find_more_paths.py ./simple.asm ./simple-trace.log ./simple-extended.log $1
python ../stitcher/src/instr_dumper.py ./simple-extended.log ./simple ./instr.s
python ../stitcher/src/find_symbols.py ./simple ./instr.s
python ../stitcher/src/stitcher.py ./simple-extended.log ./simple ./simple.s ./callbacks.txt
python ../stitcher/src/merge_bin.py simple simple.s
