#!/bin/bash

set -ex

bin_cmd=$@
cur_dir=$(dirname "$0")
root_dir=$(readlink -m $cur_dir/../)

$root_dir/pin/pin -t $root_dir/bin/trace.so -o pin_trace -- $bin_cmd
