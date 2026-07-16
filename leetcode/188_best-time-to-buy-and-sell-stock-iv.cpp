#include <bits/stdc++.h>
using namespace std;

// code_start

class Solution {
public:
  int maxProfit(int k, vector<int> &prices) {
    if (prices.size() == 0)
      return 0;
    vector<int> dp(2 * k, 0);
    for (int i = 0; i < 2 * k; i += 2) {
      dp[i] = -prices[0];
    }
    for (int i = 1; i < prices.size(); ++i) {
      dp[0] = max(dp[0], -prices[i]);
      dp[1] = max(dp[1], dp[0] + prices[i]);
      for (int j = 2; j < 2 * k; j += 2) {
        dp[j] = max(dp[j], dp[j - 1] - prices[i]);
        dp[j + 1] = max(dp[j + 1], dp[j] + prices[i]);
      }
    }
    return dp[2 * k - 1];
  }
};

// code_end
