////
//// Simple binary search in a vector
////
#include <bits/stdc++.h>
using namespace  std;

/// Find the rightmost element in array which is <= target
/// \return index of the found element. If such an element does not exist return -1
int solve(vector<int>& array, int target) {
    //1 1 1 1 0 0 0
    int l = -1, r = array.size();
    while(l+1 < r) {
        int m = (l+r) >> 1;
        if(array[m] <= target) {
            l = m;
        } else {
            r = m;
        }
    }
    return l;
}


