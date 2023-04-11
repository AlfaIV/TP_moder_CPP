#!/bin/bash
clear

cmake -S . -B tmp
cmake --build tmp
# ./tmp/main
# ./tmp/main 'echo 1 | cat file_1.txt | cat file_2.txt'
# ./tmp/main 'wc Test.txt'
echo "========Test 1=========="
./tmp/main 'wc Test.txt | echo 1'
echo "========Test 2=========="
./tmp/main 'wc Test.txt | cat 1'
echo "========Test 3=========="
./tmp/main 'wc Test.txt | ws Test.txt'