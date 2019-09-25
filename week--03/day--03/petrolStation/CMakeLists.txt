cmake_minimum_required(VERSION 3.14)
project(petrolStation)

set(CMAKE_CXX_STANDARD 14)

add_executable(petrolStation main.cpp cmake-build-debug/car.cpp cmake-build-debug/car.h cmake-build-debug/station.cpp cmake-build-debug/station.h)