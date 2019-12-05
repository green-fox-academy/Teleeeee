cmake_minimum_required (VERSION 3.8)

# Change this to the name of the directory that contains your code
set(PROJECT_LIB_NAME MyApp_lib)
# Change this to the name of the directory that contains your tests
set(PROJECT_TESTS_NAME MyApp_tests)

include_directories(${PROJECT_LIB_NAME})
add_subdirectory(${PROJECT_LIB_NAME})
add_subdirectory(${PROJECT_TESTS_NAME})

# Add source to this project's executable.
add_executable (test "test.cpp" "test.h" )

# TODO: Add tests and install targets if needed.
target_link_libraries(${PROJECT_NAME} ${PROJECT_LIB_NAME})