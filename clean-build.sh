#!/bin/bash
file_path=./build/cnipe-bot
dir_path=./build

if [[ ! -d "$dir_path" ]]; then
    mkdir "$dir_path"
else
# Clean Build Directory
    rm -rf ./build/* 
fi
cmake -B "$dir_path" 
cmake --build "$dir_path"
"$file_path"
