# CMakeList.txt : CMake project for find_contours, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

find_package(OpenCV REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )
# Add source to this project's executable.
add_executable (find_contours "find_contours.cpp" "find_contours.h")

# TODO: Add tests and install targets if needed.
target_link_libraries( find_contours ${OpenCV_LIBS} )