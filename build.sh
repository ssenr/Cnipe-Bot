#!/bin/bash
num=$(ls -l ./build | grep -c '^-')

if (( var > 0 )); then
    cmake -B ./build/ 
    cmake --build ./build 
else
    cmake --build ./build 
fi
