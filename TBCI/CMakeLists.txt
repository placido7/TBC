cmake_minimum_required(VERSION 3.20)
project(TBCI)

set(CMAKE_CXX_STANDARD 14)

add_executable(TBCI main.cpp bipartite_graph.cpp bipartite_graph.h)
