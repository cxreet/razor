#!/bin/bash

#set -ex

if [ "$1" == "clean" ]; then
	
	set -ex
	# clean up
	rm -rf logs simple_temp simple-trace.log callbacks.txt simple simple.s instr.s

elif [ "$1" == "build" ]; then

	set -ex
	# generate the binary
	gcc simple.c -O1 -o simple

elif [ "$1" == "trace" ]; then

	set -ex
	# collect the execution trace
	../tracers/scripts/trace_with_dynamorio.sh ./simple 0 y
	rm -f logs; mkdir -p logs; mv *.log logs/

elif [ "$1" == "merge_log" ]; then

	set -ex
	# combine multiple traces to one
	python ../stitcher/src/merge_log.py ./logs simple
	mv logs/simple-trace.log ./

elif [ "$1" == "dump_inst" ]; then

	set -ex
	# dump executed instructions
	python ../stitcher/src/instr_dumper.py ./simple-trace.log ./simple ./instr.s

elif [ "$1" == "instrument" ]; then

	set -ex
	# instrument executed instructions
	python ../stitcher/src/find_symbols.py ./simple ./instr.s > ./callbacks.txt
	python ../stitcher/src/stitcher.py ./simple-trace.log ./simple ./simple.s ./callbacks.txt

elif [ "$1" == "rewrite" ]; then

	set -ex
	# merge old and new code
	python ../stitcher/src/merge_bin.py simple simple.s

else
	echo "./debloat_simple.sh  clean|build|trace|merge_log|dump_inst|instrument|rewrite"
fi
