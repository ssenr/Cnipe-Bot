#!/bin/bash

# Var
var=$(ls -l ../build/ | grep -c '^-')

# Clear
if ((var > 0)); then
    # Clear Contents
    rm -rf ../build/*
fi
