#!/bin/bash

# create bin folder
mkdir bin

# configure the project and generate a native build system
cd bin
cmake ../

# compile the project
cmake --build .