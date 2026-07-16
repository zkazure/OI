#include <bits/stdc++.h>
using namespace std;

// code_start

// 关键还是在于分解子问题，把这个复杂的问题变成
// text1 前 i 个字符和 text2 前 j 个字符和下一个字符的匹配。
class Solution {
public:
  int longestCommonSubsequence(string text1, string text2) {
    int ans = 0;
    vector<vector<int>> dp(text1.length() + 1, vector(text2.length() + 1, 0));
    for (int i = 1; i <= text1.length(); ++i) {
      for (int j = 1; j <= text2.length(); ++j) {
        if (text1[i - 1] == text2[j - 1])
          dp[i][j] = dp[i - 1][j - 1] + 1;
        else
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        ans = max(dp[i][j], ans);
      }
    }
    return ans;
  }
};

// code_end
