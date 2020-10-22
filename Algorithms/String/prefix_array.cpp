#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'

void counting_sort(vector<int> &pind, vector<int> &c) {
    int s = c.size();
    vector<int> counts(s);
    for(auto e: c) counts[e] += 1;
    for(int i = 1; i < s; i++) counts[i] += counts[i-1];
    //counts[i] contains the # elems <= i
    vector<int> res (s);
    for(int i = s-1; i >=0; i--) {
        counts[c[pind[i]]] -= 1;
        res[counts[c[pind[i]]]] = pind[i];
    }
    pind = res;
}

/// Compute the prefix array for a given string S
/// \return pair: indices of sorted prefixes, longest common prefix lengths
pair<vector<int>, vector<int>> suffix_array(string& S) {
    S += "$";
    int n = S.size();
    vector<int> pind(n), c(n); // order of len 2^k prefixes, class number of each prefix
    // k == 0
    vector<pair<int,int>> a(n);
    for(int i=0; i < n; i++) a[i] = {S[i], i};
    sort(a.begin(), a.end());
    for(int i=0; i<n; i++) pind[i] = a[i].second;
    c[pind[0]] = 0;
    for(int i=1; i < n; i++)
        c[pind[i]] = a[i].first == a[i-1].first ? c[pind[i-1]] : c[pind[i-1]]+1;

    int k = 0;
    while ((1 << k) < n) {
        //k -> k+1
        for (int i=0; i < n; i++) {
            pind[i] = (pind[i] - (1 << k) + n) % n;
        }
        counting_sort(pind, c);
        vector<int> c_new(n);
        c_new[pind[0]] = 0;
        for(int i=1; i < n; i++) {
            pair<int, int> cur = { c[pind[i]], c[(pind[i] + (1 << k)) % n]};
            pair<int, int> prev = { c[pind[i-1]], c[(pind[i-1] + (1 << k)) % n]};
            if(cur == prev) {
                c_new[pind[i]] = c_new[pind[i-1]];
            } else {
                c_new[pind[i]] = c_new[pind[i-1]] + 1;
            }
        }
        c = c_new;
        k++;
    }

    // longest common prefix function
    vector<int> lcp(n);
    k = 0;
    for (int i=0; i < n-1; i++){
        int pi = c[i]; // index of s[i...] in pind
        int j = pind[pi-1];
        // lcp[pi] = lcp(s[i...], s[j...])
        while(S[i+k] == S[j+k]) k++;

        lcp[pi] = k;
        k = max(k-1, 0);
    }

    for(int i = 0; i < n-1; i++) lcp[i] = lcp[i+1];
    lcp[n-1] = 0;
    return {pind, lcp};
}
