cmake_minimum_required(VERSION 3.14)
project(sharpie)

set(CMAKE_CXX_STANDARD 14)

add_executable(sharpie main.cpp cmake-build-debug/sharpie.cpp cmake-build-debug/sharpie.h sharpieSet.cpp sharpieSet.h)