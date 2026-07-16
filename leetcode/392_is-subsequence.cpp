#include <bits/stdc++.h>
using namespace std;

// code_start

class Solution {
public:
  bool isSubsequence(string s, string t) {
    vector<vector<int>> dp(s.length() + 1, vector(t.length() + 1, 0));
    for (int i = 1; i <= s.length(); ++i) {
      for (int j = 1; j <= t.length(); ++j) {
        if (s[i - 1] == t[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
        } else {
          dp[i][j] = dp[i][j - 1];
        }
      }
    }
    if (dp[s.length()][t.length()] == s.length())
      return true;
    return false;
  }
};

// code_end

// double pointer
class Solution1 {
public:
  bool isSubsequence(string s, string t) {
    int len = 0;
    char *p = &t[0];
    while (*p != '\0' && len < s.size()) {
      if (s[len] == *p)
        len++;
      ++p;
    }

    if (len == s.size())
      return true;
    return false;
  }
};
