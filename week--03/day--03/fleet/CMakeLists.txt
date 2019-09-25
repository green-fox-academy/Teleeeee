cmake_minimum_required(VERSION 3.14)
project(fleet)

set(CMAKE_CXX_STANDARD 14)

add_executable(fleet main.cpp thing.cpp fleet.cpp fleet.h)