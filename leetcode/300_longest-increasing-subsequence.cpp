#include <bits/stdc++.h>
using namespace std;

// code_start

// 其实这个题目就是 trie tree 的思想。
class Solution {
public:
  int lengthOfLIS(vector<int> &nums) {
    if (nums.size() == 0)
      return 0;
    vector<int> dp(nums.size(), 1);
    int ans = 0;
    for (int i = 0; i < nums.size(); ++i) {
      for (int j = 0; j < i; ++j) {
        if (nums[i] > nums[j])
          dp[i] = max(dp[i], dp[j] + 1);
      }
      if (dp[i] > ans)
        ans = dp[i];
    }
    return ans;
  }
};

// code_end
