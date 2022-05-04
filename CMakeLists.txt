cmake_minimum_required(VERSION 3.19)

# set the project name
project(leetcode)

# using c++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)

# add subdirectory
add_subdirectory(array)
add_subdirectory(interview)
add_subdirectory(linkedlist)
add_subdirectory(number)
add_subdirectory(string)
add_subdirectory(tree)