cmake_minimum_required(VERSION 3.14)
project(cyrcular_buffer C)

set(CMAKE_C_STANDARD 99)

add_executable(cyrcular_buffer main.c circular_buffer.c circular_buffer.h)