#include <bits/stdc++.h>
using namespace std;

// code_start

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ans = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int idx = s.size()-1;
        for (int i=g.size()-1; i>=0; --i) {
            if (idx>=0 && s[idx]>=g[i]) {
                ans += 1;
                idx -= 1;
            }
        }
        return ans;
    }
};

// code_end
