#include <bits/stdc++.h>
using namespace std;

// code_start

class Solution {
public:
  int findMaxForm(vector<string> &strs, int m, int n) {
    int dp[101][101] = {0};
    for (auto str : strs) {
      int oneNum = 0, zeroNum = 0;
      for (char c : str) {
        if (c == '0')
          zeroNum++;
        else
          oneNum++;
      }
      for (int i = m; i >= zeroNum; --i) {
        for (int j = n; j >= oneNum; --j) {
          dp[i][j] = max(dp[i][j], dp[i - zeroNum][j - oneNum] + 1);
        }
      }
    }
    return dp[m][n];
  }
};

// code_end
