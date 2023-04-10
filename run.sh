#!/bin/bash
clear

cmake -S . -B tmp
cmake --build tmp
# ./tmp/main
./tmp/main 'echo 1 | cat file_1.txt | cat file_2.txt'