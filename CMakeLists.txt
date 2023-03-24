# set minimum cmake version
cmake_minimum_required(VERSION 3.2)

# project name and language
project(Parse_IMDB_data)

# set the C++ standard
set(CMAKE_CXX_STANDARD_REQUIRED on)

include_directories(header)
include_directories(src)

# # compile an object library for producing a shared and dynamic library
add_library(Get_films
            STATIC
            src/Get_films.cpp
            header/Get_films.h)

add_library(Get_year
            STATIC
            src/Get_year.cpp
            header/Get_year.h)

add_library(Get_local
            STATIC
            src/Get_local.cpp
            header/Get_local.h) 


add_library(Get_rating
            STATIC
            src/Get_rating.cpp
            header/Get_rating.h)   
            

add_library(Sort_films
            STATIC
            src/Sort_films.cpp
            header/Sort_films.h)    

# generate executable
add_executable(main main.cpp)

# link to shared library 
target_link_libraries(main
                    Get_films
                    Get_year
                    Get_local
                    Get_rating
                    Sort_films)
