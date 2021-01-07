//
// A simple implementation of Fenwick Tree
//

#ifndef COMPETITIVE_PROGRAMMING_FENWICK_TREE_H
#define COMPETITIVE_PROGRAMMING_FENWICK_TREE_H
#include <bits/stdc++.h>
#define llong long long

struct FenwickTree {
    int N;
    std::vector<llong> arr;

    void init(int n);

    void add(int idx, int value);

    llong psum(int idx);

    llong range_sum(int i, int j);

    void print();
};

#endif //COMPETITIVE_PROGRAMMING_FENWICK_TREE_H
