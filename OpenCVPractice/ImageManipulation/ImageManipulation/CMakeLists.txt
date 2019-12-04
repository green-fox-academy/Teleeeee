# CMakeList.txt : CMake project for ImageManipulation, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
# Add source to this project's executable.
add_executable (ImageManipulation "ImageManipulation.cpp" "ImageManipulation.h")

# TODO: Add tests and install targets if needed.
target_link_libraries( ImageManipulation ${OpenCV_LIBS} )