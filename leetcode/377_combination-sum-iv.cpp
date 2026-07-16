#include <bits/stdc++.h>
using namespace std;

// code_start

class Solution {
public:
  int combinationSum4(vector<int> &nums, int target) {
    uint64_t dp[1001] = {0};
    dp[0] = 1;
    for (int i = 1; i <= target; ++i) {
      for (int j = 0; j < nums.size(); ++j) {
        if (i >= nums[j])
          dp[i] += dp[i - nums[j]];
      }
    }
    return dp[target];
  }
};

// code_end
