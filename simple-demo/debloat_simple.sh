#!/bin/bash

set -ex

# clean up
rm -rf logs simple_temp simple-trace.log callbacks.txt simple simple.s instr.s
read -n1 ans

# generate the binary
gcc simple.c -O1 -o simple
read -n1 ans

# collect the execution trace
../tracers/scripts/trace_with_dynamorio.sh ./simple 0 y
rm -f logs; mkdir -p logs; mv dynamorio_trace logs/dynamorio_trace_simple
read -n1 ans

# combine multiple traces to one
python ../stitcher/src/merge_log.py logs simple
mv logs/simple-trace.log ./
read -n1 ans

# dump executed instructions
python ../stitcher/src/instr_dumper.py ./simple-trace.log ./simple ./instr.s
read -n1 ans

# instrument executed instructions
python ../stitcher/src/find_symbols.py ./simple ./instr.s > ./callbacks.txt
python ../stitcher/src/stitcher.py ./simple-trace.log ./simple ./simple.s ./callbacks.txt
read -n1 ans

# merge old and new code
python ../stitcher/src/merge_bin.py simple simple.s
