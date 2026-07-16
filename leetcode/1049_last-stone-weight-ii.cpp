#include <bits/stdc++.h>
using namespace std;

// code_start

class Solution {
public:
  int lastStoneWeightII(vector<int> &stones) {
    int sum = 0;
    for (int stone : stones) {
      sum += stone;
    }
    int target = sum / 2;
    int dp[1501] = {0};
    for (int i = 0; i < stones.size(); ++i) {
      for (int j = target; j >= stones[i]; --j) {
        dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
      }
    }

    return sum - dp[target] * 2;
  }
};

// code_end
