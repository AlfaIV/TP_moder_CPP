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
./tmp/main 'wc Test.txt | cat Test.txt'
echo "========Test 3=========="
./tmp/main 'wc Test.txt | wc Test.txt'
echo "========Test 4=========="
./tmp/main 'echo 1 | cat Test.txt | cat Test.txt | wc Test.txt'


cppcheck src/* header/* --enable=all
valgrind --leak-check=full ./tmp/main 'echo 1 | cat Test.txt | cat Test.txt | wc Test.txt'