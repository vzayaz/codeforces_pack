#include <bits/stdc++.h>

#define LOCAL_RELEASE
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifdef LOCAL_RELEASE
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif

    string line;
    cin >> line;

    cout <<"Hello world! Here is a line from input.txt!" <<line<<endl;
    return 0;
}