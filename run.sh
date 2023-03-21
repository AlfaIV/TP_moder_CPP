#!/bin/bash
clear
rm -df build/*

# cd data
# wget https://datasets.imdbws.com/title.akas.tsv.gz
# wget https://datasets.imdbws.com/title.ratings.tsv.gz
# wget https://datasets.imdbws.com/title.basics.tsv.gz
# gunzip title.akas.tsv.gz
# gunzip title.ratings.tsv.gz
# gunzip title.basics.tsv.gz
# cd ..

g++ main.cpp -o build/out
chmod +x build/out
# ./build/out -year 1978 -path_to_years data/itle.basics.tsv - data/title.ratings.tsv data/title.akas.tsv
./build/out -find_year 1978 -path_to_year data/title.basics.tsv -path_to_rating data/title.ratings.tsv -path_to_name data/title.akas.tsv
# ./build/out
# cd build/
# make ../