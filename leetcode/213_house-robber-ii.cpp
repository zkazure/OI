#include <bits/stdc++.h>
using namespace std;

// code_start

class Solution {
public:
  int rob(vector<int> &nums) {
    if (nums.size() == 1)
      return nums[0];

    int dp[101] = {0};
    dp[0] = 0;
    int first, second;

    dp[1] = nums[0];
    for (int i = 2; i < nums.size(); ++i) {
      dp[i] = max(dp[i - 2] + nums[i - 1], dp[i - 1]);
    }
    first = dp[nums.size() - 1];

    dp[1] = 0;
    for (int i = 2; i <= nums.size(); ++i) {
      dp[i] = max(dp[i - 2] + nums[i - 1], dp[i - 1]);
    }
    second = dp[nums.size()];

    return max(first, second);
  }
};

// code_end
