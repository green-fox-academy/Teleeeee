cmake_minimum_required(VERSION 3.14)
project(printer)

set(CMAKE_CXX_STANDARD 14)

add_executable(printer main.cpp Printer.cpp Printer.h Scanner.cpp Scanner.h Printer3D.cpp Printer3D.h Printer2D.cpp Printer2D.h Copier.cpp Copier.h)