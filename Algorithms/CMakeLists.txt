cmake_minimum_required(VERSION 3.15)

add_library(Algo Search/bin_search.cpp)

target_include_directories(Algo PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Search" )