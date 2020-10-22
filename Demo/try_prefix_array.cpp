#include "prefix_array.h"

using namespace std;

string lcs(string &S, string &T) {
    string sin = S + "#" + T;
    pair<vector<int>, vector<int>> result = suffix_array(sin);
    vector<int> order = result.first;
    vector<int> lcp = result.second;

    int res = 0;
    int istart = -1;

    for(int i = 1; i < order.size(); i++){
        int cur_type = (order[i] <= S.size()) ? 1:2;
        int prev_type = (order[i-1] <= S.size()) ? 1:2;
        if (cur_type != prev_type && res < lcp[i-1]) {
            res = lcp[i-1];
            istart = min(order[i], order[i-1]);
        }

    }
    return istart >= 0? S.substr(istart, res) : "";
}


int main() {
    string S, T;
    cout << "Enter S"<<endl;
    cin >> S;
    cout << "Enter T"<<endl;
    cin >> T;
    string result = lcs(S, T);
    cout <<"Longest common string is " <<result <<endl;
    return 0;
}