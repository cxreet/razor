#!/bin/bash

# clean up
#echo -n "" > /tmp/123
echo -n "" > pt_trace_log
#echo -n "" > trace_dump
rm -f perf.data-aux-idx*.bin 
rm -f perf.data-sideband-cpu*.pevent
rm -f perf.data*
rm -f pt_trace_log*
rm -rf sysroot
