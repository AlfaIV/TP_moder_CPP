#!/bin/bash
clear
cd /home/alfaiv/Code/TP_VK/modern_cpp/HM1
rm -rf build/*

# cd data
# wget https://datasets.imdbws.com/title.akas.tsv.gz
# wget https://datasets.imdbws.com/title.ratings.tsv.gz
# wget https://datasets.imdbws.com/title.basics.tsv.gz
# gunzip title.akas.tsv.gz
# gunzip title.ratings.tsv.gz
# gunzip title.basics.tsv.gz
# cd ..

# g++ main.cpp Get_films.cpp Get_year/Get_year.cpp Get_rating/Get_rating.cpp Get_local/Get_local.cpp Sort_films/Sort_films.cpp -o build/out
# chmod +x build/out
# # ./build/out -find_year 1895 -path_to_year data/title.basics.tsv -path_to_rating data/title.ratings.tsv -path_to_name data/title.akas.tsv
# ./build/out -find_year 1895 -path_to_name data/title.akas.tsv -path_to_year data/exampl_basics.tsv -path_to_rating data/exampl_rating.tsv


cmake -S . -B build
cmake --build build
./build/main -find_year 1895 -path_to_name data/title.akas.tsv -path_to_year data/exampl_basics.tsv -path_to_rating data/exampl_rating.tsv