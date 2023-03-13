#!/bin/bash
clear
rm build/*
g++ main.cpp -o build/out
chmod +x build/out
./build/out
