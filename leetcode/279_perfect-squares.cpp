#include <bits/stdc++.h>
using namespace std;

// code_start

class Solution {
public:
  int numSquares(int n) {
    vector<int> dp(10001, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i * i <= n; ++i) {
      int square = i * i;
      for (int j = square; j <= n; ++j) {
        if (dp[j - square] != INT_MAX)
          dp[j] = min(dp[j], dp[j - square] + 1);
      }
    }
    return dp[n];
  }
};

// code_end
