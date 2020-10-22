//
// UnionFind data structure with rollbacks. Useful for offline dynamic connectivity problem
//
#include <bits/stdc++.h>
using namespace  std;
#define endl '\n'

class UnionFind {
    struct Op {
        int big, small, delta;
    };

    int* par;
    int* len;
    stack<int> cp_ops;
    stack<Op> rev_ops;
    bool write = false;

public:
    int n;
    explicit UnionFind(int n) {
        this->n = n;
        par = new int[n];
        len = new int[n];
        for(int i=0; i<n; i++) {
            par[i] = i;
            len[i] = 1;
        }
        cp_ops.push(0);
    }

    int get(int i) {
        if (par[i] == i) return i;
        return get(par[i]);
    }

    void persist() {
        cp_ops.push(0);
        write = true;
    }

    int rollback() {
        int count = cp_ops.top();
        cp_ops.pop();
        for (int i=0; i<count; i++) {
            const Op& op = rev_ops.top();
            rev_ops.pop();
            par[op.small] = op.small;
            len[op.big] -= op.delta;
            n++;
        }
        write = false;
        return n;
    }


    int merge(int ia, int ib) {
        auto a = get(ia);
        auto b = get(ib);
        if(a == b) {
            return n;
        }
        if(len[a] < len[b]) {
            swap(a, b);
        }
        par[b] = a;
        len[a] += len[b];
        n--;
        if (write) {
            rev_ops.push({a, b, len[b]});

            int op_count = cp_ops.top();
            cp_ops.pop();
            cp_ops.push(op_count + 1);
        }
        return n;
    }

};