# CMakeList.txt : CMake project for MeasureAngle, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

find_package(OpenCV)
include_directories( ${OpenCV_INCLUDE_DIRS} )
# Add source to this project's executable.
add_executable (MeasureAngle "MeasureAngle.cpp" "MeasureAngle.h")

# TODO: Add tests and install targets if needed.
target_link_libraries( MeasureAngle ${OpenCV_LIBS} )