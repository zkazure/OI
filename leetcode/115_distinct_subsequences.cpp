#include <string>
using namespace std;

// 由于没有限制 s 的长度，我们必须使用一维 dp
class Solution1 {
  public:
    int numDistinct(string s, string t) {
        int ans = 0;
        int dp[100][100] = {0};
        if (s[0] == t[0])
            dp[1][0] = 1;
        for (int i = 1; i <= t.length(); ++i) {
            // i is length of matching string
            for (int j = i - 1; j < s.length(); ++j) {
                // j is the end char going to check
                if (s[j] == t[i - 1]) {
                    if (i == 1) {
                        dp[i][j] = 1;
                    } else {
                        for (int k = 0; k < j; ++k) {
                            dp[i][j] += dp[i - 1][k];
                        }
                    }
                }
            }
        }
        for (int i = 0; i < s.length(); ++i) {
            ans += dp[t.length()][i];
        }

        return ans;
    }
};

class Solution2 {
  public:
    int numDistinct(string s, string t) {
        int ans = 0;
        unsigned long long dp[s.length()];
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == t[0])
                dp[i] = 1;
            else
                dp[i] = 0;
        }
        for (int j = 1; j < t.length(); ++j) {
            for (int i = s.length() - 1; i >= 0; --i) {
                dp[i] = 0;
                if (s[i] == t[j]) {
                    for (int k = 0; k < i; ++k) {
                        dp[i] += dp[k];
                    }
                }
            }
        }

        for (int i : dp)
            ans += i;

        return ans;
    }
};

class Solution {
  public:
    int numDistinct(string s, string t) {
        unsigned long long dp[1001] = {0};
        dp[0] = 1;

        for (int i = 0; i < s.length(); ++i) {
            for (int j = t.length(); j >= 1; --j) {
                if (s[i] == t[j - 1]) {
                    dp[j] += dp[j - 1];
                }
            }
        }

        return dp[t.length()];
    }
};

int main() {
    // string s = "babgbag";
    // string t = "bag";
    string s = "rabbbit";
    string t = "rabbit";
    Solution solution;
    int b = solution.numDistinct(s, t);
}
