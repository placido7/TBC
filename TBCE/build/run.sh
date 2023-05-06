#!/bin/bash
params=(0.01)
for param in "${params[@]}"; do
    ./TBCE ../Linux.txt ../Linux-TBCE.txt 86400 "$param"
done
