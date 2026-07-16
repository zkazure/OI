#include <bits/stdc++.h>
using namespace std;

// code_start

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int dp[1005];
        dp[0]=0, dp[1]=0;
        int n=cost.size();
        for (int i=2; i<=n; ++i) {
            int a = dp[i-2] + cost[i-2];
            int b = dp[i-1] + cost[i-1];
            dp[i] = (a>b) ? b : a;
        }

        return dp[n];
    }
};

// code_end

