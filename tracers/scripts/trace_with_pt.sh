#!/bin/bash

################################################################################
#
#        make sure you know the expected loading address of the binary
#
#			   (as root) echo -1 > /proc/sys/kernel/perf_event_paranoid
#
#################################################################################

set -ex

# clean up
#echo -n "" > /tmp/123
echo -n "" > pt_trace_log
#echo -n "" > trace_dump
rm -f perf.data-aux-idx*.bin 
rm -f perf.data-sideband-cpu*.pevent
rm -f perf.data*
rm -f pt_trace
rm -rf sysroot

bin_cmd=$@
cur_dir=$(dirname "$0")
root_dir=$(readlink -m $cur_dir/../)

# generate trace for /bin/ls
#
# -m:   set the buffer size
# -e:   the event to capture, here is intel_pt
#       tsc=0,mtc=0:disable particular packages
#       u: user space event only
# --per-thread:
# -a, --all-cpus
#       System-wide collection from all CPUs.
# --switch-events:
#       Record context switch events i.e. events of type PERF_RECORD_SWITCH or
#       PERF_RECORD_SWITCH_CPU_WIDE.
# -T:   timestamp
# --filter: 
#       filter start_address / size @path-to-file
# -- command options
#
#echo "recoring" >> /tmp/123
#/usr/bin/time -p -a -o /tmp/123 
perf record -m 512,10000 -e intel_pt/noretcomp/u  --switch-events -T -- $bin_cmd

# extract the raw PT trace
#echo "extract aux" >> /tmp/123
#/usr/bin/time -p -a -o /tmp/123 
$root_dir/pt/script/perf-read-aux.bash
#echo "" >> /tmp/123

# extract the sideband information
#echo "extract sideband" >> /tmp/123
#/usr/bin/time -p -a -o /tmp/123 
$root_dir/pt/script/perf-read-sideband.bash
#echo "" >> /tmp/123

# get the trace dump
#echo "ptdump" >> /tmp/123
#for aux_data in $(ls perf.data-aux-idx*.bin); do
#  echo $aux_data
  #/usr/bin/time -p -a -o /tmp/123 $root_dir/bin/ptdump $($root_dir/pt/script/perf-get-opts.bash) $aux_data &>> trace_dump
#done
#echo "" >> /tmp/123

# get the instruction dump
#echo "ptxed" >> /tmp/123

# dump all necessary binary & libraries & vdso
# what I want is only vdso
$root_dir/pt/script/perf-copy-mapped-files.bash -o sysroot

for aux_data in $(ls perf.data-aux-idx*.bin); do
	a=${aux_data:17}
	b=${a:0:(${#a}-4)}
	$root_dir/bin/ptxed --pevent:vdso-x64 sysroot/vdso/vdso-x64.so $($root_dir/pt/script/perf-get-opts.bash -m perf.data-sideband-cpu$b.pevent) --event:tick --decode-to-debloat --no-inst --pt $aux_data >> pt_trace
done
#echo "" >> /tmp/123

# clean up
#echo -n "" > /tmp/123
echo -n "" > pt_trace_log
#echo -n "" > trace_dump
rm -f perf.data-aux-idx*.bin 
rm -f perf.data-sideband-cpu*.pevent
rm -f perf.data*
rm -rf sysroot
