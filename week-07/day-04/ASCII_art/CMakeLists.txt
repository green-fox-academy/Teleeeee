cmake_minimum_required(VERSION 3.14)
project(ASCII_art C)

set(CMAKE_C_STANDARD 99)

add_executable(ASCII_art main.c bmp_utility.c bmp_utility.h command_line_read.c command_line_read.h)