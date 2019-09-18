cmake_minimum_required(VERSION 3.14)
project(drawAll)

set(CMAKE_CXX_STANDARD 14)


set(SDL2_ROOT_PATH C:/SDL2_windows)

set(EXECUTABLES "draw;starynight;tocenter;connectTheDots;functiontoCenter;checkerboard;purpleSteps3D;purpleSteps;rainbowSquares;centerBoxFunction;diagonals;horizontalline;coloredBox;goToCenter;horizontal;square;fillWithRectangels;squarepositioning")
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

IF(WIN32)
    set(MINGW_VERSION i686-w64-mingw32)
ENDIF()

find_package(SDL2_all REQUIRED)
