#!/bin/bash

bin_cmd="/bin/ls /var"

set -ex

cur_dir=$(pwd)
root_dir=$(readlink -m $cur_dir/../)

# trace with main binary only
$root_dir/dynamorio/bin64/drrun -c $root_dir/bin/libcbr_indcall.so -- $bin_cmd

# tracing with all libraries
$root_dir/dynamorio/bin64/drrun -c $root_dir/bin/libcbr_indcall.so --lib -- $bin_cmd

echo "you can find trace in $root_dir/bin/*.log"
