#include <bits/stdc++.h>
using namespace std;

// code_start

class Solution {
public:
    int numTrees(int n) {
        int dp[21] = {1, 1, 2};
        for (int i=3; i<=n; ++i) {
            for (int j=0; j<i; ++j) {
                dp[i] += dp[j] * dp[i-j-1];
            }
        }
        return dp[n];
    }
};

// code_end

