cmake_minimum_required(VERSION 3.15)
project(C__)

set(CMAKE_CXX_STANDARD 14)

add_executable(SortingAlgorithms algorithms/SortingAlgorithms.cpp)

# leetcode
add_executable(leetcode-1-tow-sum leetcode/1-tow-sum.cpp)