cmake_minimum_required(VERSION 3.14)
project(oopTest)

set(CMAKE_CXX_STANDARD 14)

add_executable(oopTest main.cpp cmake-build-debug/Rectangle.cpp cmake-build-debug/Rectangle.h cmake-build-debug/postIt.cpp cmake-build-debug/postIt.h cmake-build-debug/BlogPost.cpp cmake-build-debug/BlogPost.h cmake-build-debug/Animals.cpp cmake-build-debug/Animals.h)