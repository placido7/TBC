#!/bin/bash
#!/bin/bash

input_file="../../dataset/Linux.txt"

for alpha in 1
do
    for beta in 400
    do
        output_filename="../reddit-${alpha}-${beta}.txt"
        ./TBCI $input_file $output_filename 86400 $alpha $beta
    done
done