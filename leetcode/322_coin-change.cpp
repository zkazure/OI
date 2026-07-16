#include <bits/stdc++.h>
using namespace std;

// code_start

class Solution {
public:
  int coinChange(vector<int> &coins, int amount) {
    vector<uint64_t> dp(10001, INT_MAX);
    dp[amount] = -1;
    dp[0] = 0;
    for (int i = 0; i < coins.size(); ++i) {
      for (int j = coins[i]; j <= amount; ++j) {
        if (dp[j - coins[i]] != INT_MAX)
          dp[j] = min(dp[j - coins[i]] + 1, dp[j]);
      }
    }
    return dp[amount];
  }
};

// code_end
