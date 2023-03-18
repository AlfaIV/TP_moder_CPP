#!/bin/bash
clear
rm build/*
g++ main.cpp -o build/out
chmod +x build/out
./build/out data/title.basics.tsv data/title.ratings.tsv data/title.akas.tsv
