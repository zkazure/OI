#include <bits/stdc++.h>
using namespace std;

// code_start

// 其实就是最长公共子序列
class Solution {
public:
  int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2) {
    int ans = 0;
    vector<vector<int>> dp(nums1.size() + 1, vector(nums2.size() + 1, 0));
    for (int i = 1; i <= nums1.size(); ++i) {
      for (int j = 1; j <= nums2.size(); ++j) {
        if (nums1[i - 1] == nums2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
          ans = max(ans, dp[i][j]);
        } else
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
    return ans;
  }
};

// code_end
