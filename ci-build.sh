#!/bin/bash

cd c
mkdir build
cd build
cmake ..
make -j 
make do-all-tests
cd ../..
