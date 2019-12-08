# CMakeList.txt : CMake project for funWithOpenCv, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

find_package(OpenCV)
include_directories( ${OpenCV_INCLUDE_DIRS} )
# Add source to this project's executable.
add_executable (funWithOpenCv "filters.h" "filters.cpp" "funWithOpenCv.cpp" "funWithOpenCv.h" "UART.h" "UART.cpp")


# TODO: Add tests and install targets if needed.
target_link_libraries( funWithOpenCv ${OpenCV_LIBS} )