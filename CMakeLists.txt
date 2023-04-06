# set minimum cmake version
cmake_minimum_required(VERSION 3.2)

# project name and language
project(CLI_command)

# set the C++ standard
set(CMAKE_CXX_STANDARD_REQUIRED on)

include_directories(header)
include_directories(src)

# # compile an object library for producing a shared and dynamic library
#add_library(Get_films
#	    STATIC
#	    src/Get_films.cpp
#	    header/Get_films.h)

# generate executable
add_executable(main
               src/main.cpp)

 # link to shared library 

target_link_libraries(main)

