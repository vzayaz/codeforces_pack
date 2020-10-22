cmake_minimum_required(VERSION 3.15)

set(CMAKE_CXX_STANDARD 14)

add_executable(Solution template.cpp)

configure_file(input.txt  "${CMAKE_CURRENT_BINARY_DIR}/input.txt" COPYONLY)