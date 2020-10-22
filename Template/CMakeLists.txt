add_executable(Solution template.cpp)

configure_file(input.txt  "${CMAKE_CURRENT_BINARY_DIR}/input.txt" COPYONLY)