cmake_minimum_required(VERSION 3.14)
project(zoo)

set(CMAKE_CXX_STANDARD 14)

add_executable(zoo main.cpp Animal.cpp Animal.h Mammal.cpp Mammal.h Reptile.cpp Reptile.h Bird.cpp Bird.h)