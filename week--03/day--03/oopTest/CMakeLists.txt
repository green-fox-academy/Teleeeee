cmake_minimum_required(VERSION 3.14)
project(oopTest)

set(CMAKE_CXX_STANDARD 14)

add_executable(oopTest main.cpp cmake-build-debug/Rectangle.cpp cmake-build-debug/Rectangle.h)