cmake_minimum_required(VERSION 3.14)
project(coloredBox)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(coloredBox
    CMakeLists.txt
    draw.cpp
    draw.h
    main.cpp)
