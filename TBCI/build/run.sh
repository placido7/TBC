#!/bin/bash

#Store all S values for different C values
declare -A params=(
  ["1"]="1000"
)
# Iterate over all parameter combinations
for paramC in "${!params[@]}"; do
  # Create output file
  output_file="C${paramC}_output.txt"
  touch $output_file
  # Iterate over all S values for current C value
  for paramS in ${params[$paramC]}; do
    #  Execute the algorithm and append the result to the output file
    ./TBCI ../Linux.txt "$output_file" 86400 "$paramC" "$paramS" 
  done
done