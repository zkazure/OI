#include <bits/stdc++.h>
using namespace std;

// code_start

class Solution {
public:
  int findLengthOfLCIS(vector<int> &nums) {
    if (nums.size() == 0)
      return 0;
    vector<int> dp(nums.size(), 1);
    int ans = 1;

    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] > nums[i - 1])
        dp[i] = dp[i - 1] + 1;
      ans = dp[i] > ans ? dp[i] : ans;
    }
    return ans;
  }
};

// code_end
