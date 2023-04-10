#!/bin/bash
clear

cmake -S . -B tmp
cmake --build tmp
./tmp/main