#!/bin/bash
file_path=./src/cnipe-bot

if [[ -x "$file_path" ]]; then
    rm "$file_path"
fi 

g++ ./src/main.cpp -o "$file_path" -ldpp

"$file_path"
