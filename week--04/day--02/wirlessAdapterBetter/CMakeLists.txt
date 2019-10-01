cmake_minimum_required(VERSION 3.14)
project(wirlessAdapterBetter)

set(CMAKE_CXX_STANDARD 14)

add_executable(wirlessAdapterBetter main.cpp Device.cpp Device.h NetworkDevice.cpp NetworkDevice.h UsbDevice.cpp UsbDevice.h WirelessAdapter.cpp WirelessAdapter.h)