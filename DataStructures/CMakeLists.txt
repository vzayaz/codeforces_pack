add_library(DS
        "DSU/dsu.cpp"
        "SegmentTree/segment_tree.cpp"
        "FenwickTree/fenwick_tree.cpp"
        )

target_include_directories(DS PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/DSU"
        "${CMAKE_CURRENT_SOURCE_DIR}/SegmentTree"
        "${CMAKE_CURRENT_SOURCE_DIR}/FenwickTree"
        )