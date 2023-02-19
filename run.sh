#!/bin/bash
file_pth=./build/cnipe-bot
dir_pth=./build

if [ -x "$file_pth" ]; then
    ./build/cnipe-bot
elif [ -d "$dir_pth" ]; then
    cmake -B ./build
    cmake --build ./build
else    
    mkdir ./build
    cmake -B ./build
    cmake --build ./build
fi
