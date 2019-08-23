#!/bin/bash

bin_cmd="/bin/ls /var"

set -e

cur_dir=$(pwd)
root_dir=$(readlink -m $cur_dir/../)

$root_dir/pin/pin -t $root_dir/bin/trace.so -o abc -- $bin_cmd

echo "you can find the trace in abc-*"
