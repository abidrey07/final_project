cmake_minimum_required(VERSION 4.0)
project(finalproject)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
#include directory
include_directories(include)
#source files
set(src/main.cpp)
add_executable(finalproject src/main.cpp
        include/controller.h
        include/button.h
        include/joystick.h
)
