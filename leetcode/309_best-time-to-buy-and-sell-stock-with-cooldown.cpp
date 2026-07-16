#include <bits/stdc++.h>
using namespace std;

// code_start

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    if (prices.size() < 2)
      return 0;
    int dp[4] = {0};
    dp[0] = -prices[0];
    for (int i = 1; i < prices.size(); ++i) {
      dp[0] = max(dp[0], dp[3] - prices[i]); // 持有股票时的最大利润
      dp[1] = max(dp[1], dp[0] + prices[i]); // 售出股票后的最大利润
      dp[3] = dp[2]; // 保存昨天的最大利润，下次循环就变成前天
      dp[2] = dp[1]; // 保存今天最大利润
    }
    return dp[1];
  }
};

// code_end
