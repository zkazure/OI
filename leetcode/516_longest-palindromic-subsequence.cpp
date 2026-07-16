#include <bits/stdc++.h>
using namespace std;

// code_start

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        for (int i = 0; i < s.size(); ++i) dp[i][i] = 1;
        for (int i = 0; i < s.size(); ++i) {
            for (int j = i - 1; j >= 0; --j) {
                dp[i][j] = (s[i] == s[j])
                    ? dp[i - 1][j + 1] + 2
                    : max(dp[i - 1][j], dp[i][j + 1]);
            }
        }
        return dp[s.size() - 1][0];
    }
};

// code_end
