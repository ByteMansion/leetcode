#!/bin/bash

# create bin folder
if [ -e build ]
then
    rm -fr build/*
fi

cmake -S . -B build
cmake --build build -j16
