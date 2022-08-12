#!/bin/bash

# create bin folder
if [ -e build ]
then
    cmake --build build -j8
else
    cmake -S . -B build
fi
