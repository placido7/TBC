###
### Sampling Algorithms for Butterfly Counting on Temporal Bipartite Graphs
###

All algorithms were implemented in C++14 compiled by GCC v9.4, and ran on a single thread.

### For Linux

Here is an example of how to use the code:
```
# Build the code
cd TBC/TBCE/build

cmake ..

make

# Run all algorithms TBC-E, TBC-N, TBC-I

# Example
./TBCE ../../datasets/Linux.txt  ../out.txt 86400 0.01

# Parameters
TBC-E: Please input five parameters: input file, output file, delta, edge sampling rate P

TBC-E: Please input five parameters: input file, output file, delta, node sampling rate P

TBC-I: Please input five parameters: input file, output file, delta, interval multiplier C,number of samples s


