#include <bits/stdc++.h>
using namespace std;

// code_start

class Solution {
public:
  int change(int amount, vector<int> &coins) {
    uint64_t dp[5001] = {0};
    dp[0] = 1;
    for (int i = 0; i < coins.size(); ++i) {
      for (int j = coins[i]; j <= amount; ++j) {
        dp[j] += dp[j - coins[i]];
      }
    }
    return dp[amount];
  }
};

// code_end
