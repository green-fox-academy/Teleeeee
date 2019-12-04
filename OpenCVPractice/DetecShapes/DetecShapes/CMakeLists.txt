# CMakeList.txt : CMake project for DetecShapes, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
# Add source to this project's executable.
add_executable (DetecShapes "DetecShapes.cpp" "DetecShapes.h" "line_detect.h" "line_detect.cpp")

# TODO: Add tests and install targets if needed.
target_link_libraries( DetecShapes ${OpenCV_LIBS} )