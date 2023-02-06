#!/bin/bash

# create bin folder
if [ -e build ]
then
    rm -fr build
else
    cmake -S . -B build
fi

cmake --build build -j16
