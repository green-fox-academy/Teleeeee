cmake_minimum_required(VERSION 3.14)
project(pirates)

set(CMAKE_CXX_STANDARD 14)

add_executable(pirates main.cpp Pirate.cpp Pirate.h pirateShip.cpp pirateShip.h Armada.cpp Armada.h)