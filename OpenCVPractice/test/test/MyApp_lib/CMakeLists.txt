# Add all your .cpp files here (separated by spaces)
add_library(${PROJECT_LIB_NAME} myClass.cpp)

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

target_link_libraries( ${PROJECT_LIB_NAME} ${OpenCV_LIBS} )