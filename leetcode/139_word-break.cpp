#include <bits/stdc++.h>
using namespace std;

// code_start

class Solution {
public:
  bool wordBreak(string s, vector<string> &wordDict) {
    unordered_set<string> words(wordDict.begin(), wordDict.end());
    vector<bool> dp(s.size() + 1, false);
    dp[0] = true;
    for (int i = 1; i <= s.size(); ++i) {
      for (int j = 0; j < i; ++j) {
        string word = s.substr(j, i - j);
        if (dp[j] && words.find(word) != words.end())
          dp[i] = true;
      }
    }
    return dp[s.size()];
  }
};

// code_end
