cmake_minimum_required(VERSION 3.19)

# using c++11
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# set the project name
project(leetcode)

# add subdirectory
add_subdirectory(array)
add_subdirectory(interview)
add_subdirectory(linkedlist)
add_subdirectory(number)
add_subdirectory(string)
add_subdirectory(tree)