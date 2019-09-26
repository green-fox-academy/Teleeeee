cmake_minimum_required(VERSION 3.14)
project(blogpostBlog)

set(CMAKE_CXX_STANDARD 14)

add_executable(blogpostBlog main.cpp BlogPost.cpp BlogPost.h Blog.cpp Blog.h postIt.cpp postIt.h)