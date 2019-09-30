cmake_minimum_required(VERSION 3.14)
project(airCraftCarrier)

set(CMAKE_CXX_STANDARD 14)

add_executable(airCraftCarrier main.cpp F16.cpp F16.h F35.cpp F35.h Aircraft.cpp Aircraft.h Carrier.cpp Carrier.h)