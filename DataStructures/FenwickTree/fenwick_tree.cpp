#include "fenwick_tree.h"
using namespace  std;
#define endl '\n'

void FenwickTree::init(int n) {
    N = n;
    arr = vector<llong>(n+1, 0);
}

void FenwickTree::add(int idx, int value) {
    while (idx <= N) {
        arr[idx] += value;
        idx += idx & (-idx);
    }
}

llong FenwickTree::psum(int idx) {
    llong res = 0;
    while (idx > 0) {
        res += arr[idx];
        idx -= idx & (-idx);
    }
    return res;
}

llong FenwickTree::range_sum(int i, int j) {
    return psum(j) - psum(i-1);
}

void FenwickTree::print() {
    for (int i=1;i<=N;i++) cout << arr[i] << " ";
    cout << endl;
}
