#include <bits/stdc++.h>
#include "bin_search.h"

using namespace std;

int main() {
    vector<int> array { 1, 3, 5, 5, 7, 10};
    int result = solve(array, 7);
    cout <<"Search result is " <<result <<endl;
    return 0;
}