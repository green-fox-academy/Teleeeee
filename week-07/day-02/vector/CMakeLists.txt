cmake_minimum_required(VERSION 3.14)
project(vector C)

set(CMAKE_C_STANDARD 99)

add_executable(vector main.c vector.c vector.h generic_vector.c generic_vector.h)