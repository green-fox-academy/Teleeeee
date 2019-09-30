cmake_minimum_required(VERSION 3.14)
project(gardenBetter)

set(CMAKE_CXX_STANDARD 14)

add_executable(gardenBetter main.cpp Plant.cpp Plant.h Flowers.cpp Flowers.h Trees.cpp Trees.h Garden.cpp Garden.h)