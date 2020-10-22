///
/// Segment tree implementation to find minimum element in a given range and it's number of occurrences
///
#include <bits/stdc++.h>
using namespace  std;
#define endl '\n'

struct Node {
    long long value;
    int count;
};

struct STree {

  int n, size;
  Node* array;
  Node ZERO = {INT_MAX, 0};

  void init(int nn) {
      n = nn;
      size = 1;
      while (size < n) size *= 2;
      array = new Node[2 * size - 1];
      for (int i = 0; i < 2 * size - 1; i++) {
          array[i] = ZERO;
      }
  }

  void set(int i, int v) {
      set(0, i, v, 0, size);
  }

  void set(int inode, int i, int v, int l, int r){
      if (r-l == 1) {
          array[inode] = {v, 1};
          return;
      }
      int m = (l+r) / 2;
      if (i < m) set(inode * 2 + 1, i, v, l, m);
      else set(inode * 2 + 2, i, v, m, r);
      array[inode] = agg(array[inode * 2 + 1], array[inode * 2 + 2]);
  }

  Node agg(Node left, Node right) {
      if (left.value < right.value) return left;
      if (right.value < left.value) return right;
      return {left.value, left.count + right.count};
  }

  Node value(int l, int r) {
      long long result = 0;
      return value(0, 0, size, l, r);
  }

  Node value(int inode, int lnode, int rnode, int ll, int rr) {
      // node has ann intersection with the interval
      if (ll <= lnode && rnode <= rr) return array[inode];
      if (rnode <= ll || rr <= lnode) return ZERO;
      int m = (lnode + rnode) / 2;
      return agg(value(inode * 2 + 1, lnode, m, ll, rr), value(inode * 2 + 2, m, rnode, ll, rr));
  }
};

//int main() {
//    std::ios::sync_with_stdio(false);
//    int n, m;
//    cin >> n >> m;
//    int ai;
//    STree tree;
//    tree.init(n);
//    for (int i = 0; i < n; i++) {
//        cin >> ai;
//        tree.set(i, ai);
//    }
//    int op, a1, a2;
//    for (int i=0; i < m; i++) {
//        cin >> op >> a1 >> a2;
//        if(op == 1) {
//            tree.set(a1, a2);
//        }
//        else {
//            Node res = tree.value(a1, a2);
//            cout <<  res.value <<" " << res.count << endl;
//        }
//    }
//    return 0;
//}
