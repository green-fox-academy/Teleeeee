cmake_minimum_required (VERSION 3.8)

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
# Add source to this project's executable.
add_executable (Remapping "Remapping.cpp" "Remapping.h" )

# TODO: Add tests and install targets if needed.
target_link_libraries( Remapping ${OpenCV_LIBS} )