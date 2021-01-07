add_executable(DemoBin try_bin_search.cpp)
target_link_libraries(DemoBin LINK_PUBLIC Algo)

add_executable(DemoLcs try_prefix_array.cpp)
target_link_libraries(DemoLcs LINK_PUBLIC Algo)

add_executable(DemoFenwick try_fenwick_tree.cpp)
target_link_libraries(DemoFenwick LINK_PUBLIC Algo DS)