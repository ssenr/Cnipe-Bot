#!/bin/bash
# Build and Run
dir_path=./build

if [[ ! -d "$dir_path" ]]; then
    mkdir ./build 
fi
cmake -B ./build 
cmale --build ./build 
./build/cnipe-bot
