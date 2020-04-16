#!/bin/bash

set -ex

# clean up
rm -rf logs simple_temp simple-trace.log callbacks.txt simple simple.s instr.s

# generate the binary
gcc simple.c -O1 -o simple

# collect the execution trace
../tracers/scripts/trace_with_dynamorio.sh ./simple 0 y
rm -f logs; mkdir -p logs
cp ../tracers/bin/libcbr_indcall.so ./logs/
mv dynamorio_trace logs/dynamorio_trace_simple

# combine multiple traces to one
python ../stitcher/src/merge_log.py logs simple
mv logs/simple-trace.log ./

# dump executed instructions
python ../stitcher/src/instr_dumper.py ./simple-trace.log ./simple ./instr.s

# instrument executed instructions
python ../stitcher/src/find_symbols.py ./simple ./instr.s > ./callbacks.txt
python ../stitcher/src/stitcher.py ./simple-trace.log ./simple ./simple.s ./callbacks.txt

# merge old and new code
python ../stitcher/src/merge_bin.py simple simple.s
