#include <bits/stdc++.h>
using namespace std;

// code_start

// 这种 dp 其实相当于把所有的可能相同的子数组的可能性都做了尝试。
class Solution {
public:
  int findLength(vector<int> &nums1, vector<int> &nums2) {
    vector<vector<int>> dp(nums1.size() + 1, vector(nums2.size() + 1, 0));
    int ans = 0;
    for (int i = 1; i <= nums1.size(); ++i) {
      for (int j = 1; j <= nums2.size(); ++j) {
        if (nums1[i - 1] == nums2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
          ans = max(ans, dp[i][j]);
        }
      }
    }
    return ans;
  }
};

// code_end

class Solution1 {
public:
  int findLength(vector<int> &nums1, vector<int> &nums2) {
    vector<vector<int>> dp(nums1.size() + 1, vector(nums2.size() + 1, 0));
    int ans = 0;
    for (int i = nums1.size() - 1; i >= 0; --i) {
      for (int j = nums2.size() - 1; j >= 0; --j) {
        if (nums1[i] == nums2[j])
          dp[i][j] = dp[i + 1][j + 1] + 1;
        ans = max(ans, dp[i][j]);
      }
    }
    return ans;
  }
};
