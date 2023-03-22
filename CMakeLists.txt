# set minimum cmake version
cmake_minimum_required(VERSION 3.2)

# project name and language
project(Parse_IMDB_data)

# set the C++ standard
# set(CMAKE_CXX_COMPILER g++)
# set(CMAKE_CXX_FLAGS_RELEASE_INIT "-Wall")
set(CMAKE_CXX_STANDARD_REQUIRED on)
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")

# # compile an object library for producing a shared and dynamic library
add_library(Get_films
            STATIC
            Get_films.cpp
            Get_films.h)

add_library(Get_year
            STATIC
            Get_year/Get_year.cpp
            Get_year/Get_year.h)

add_library(Get_local
            STATIC
            Get_local/Get_local.cpp
            Get_local/Get_local.h) 


add_library(Get_rating
            STATIC
            Get_rating/Get_rating.cpp
            Get_rating/Get_rating.h)   
            

add_library(Sort_films
            STATIC
            Sort_films/Sort_films.cpp
            Sort_films/Sort_films.h)    

# generate executable
add_executable(main main.cpp)

# target_compile_definitions(main PRIVATE USE_DEBUG)
# link to shared library 
target_link_libraries(main
                    Get_films
                    Get_year
                    Get_local
                    Get_rating
                    Sort_films)
