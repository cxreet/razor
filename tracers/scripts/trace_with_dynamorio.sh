#!/bin/bash

set -ex

bin_cmd=$@
cur_dir=$(dirname "$0")
root_dir=$(readlink -m $cur_dir/../)

# trace with main binary only
$root_dir/dynamorio/bin64/drrun -c $root_dir/bin/libcbr_indcall.so -- $bin_cmd

# tracing with all libraries
#$root_dir/dynamorio/bin64/drrun -c $root_dir/bin/libcbr_indcall.so --lib -- $bin_cmd

mv $root_dir/bin/*.log dynamorio_trace
