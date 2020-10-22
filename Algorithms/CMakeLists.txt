add_library(Algo
        Search/bin_search.cpp
        String/prefix_array.cpp)

target_include_directories(Algo PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/Search"
        "${CMAKE_CURRENT_SOURCE_DIR}/String")