#!/bin/bash
params=(0.01)
for param in "${params[@]}"; do
    ./TBCN ../../Linux.txt ../Linux-TBCN.txt 86400 "$param"
done
