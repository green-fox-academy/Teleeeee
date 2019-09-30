cmake_minimum_required(VERSION 3.14)
project(gardenApplication)

set(CMAKE_CXX_STANDARD 14)

add_executable(gardenApplication main.cpp Flowers.cpp Flowers.h Garden.cpp Garden.h Trees.cpp Trees.h)