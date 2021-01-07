#include "fenwick_tree.h"
using namespace std;

int main() {

    int values[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = 10;
    FenwickTree tree;
    tree.init(10);
    tree.print();
    for(int i = 0; i < n; i++) tree.add(i+1, values[i]);
    tree.print();

    cout << tree.range_sum(1, 5) <<endl;
    cout << tree.range_sum(1, 10) <<endl;
    cout << tree.range_sum(2, 3) <<endl;
    cout << tree.range_sum(3, 3) <<endl;

    return 0;
}