#include <bits/stdc++.h>
using namespace std;

// code_start
class Solution {
public:
    int countSubstrings(string s) {
        string str = "^";
        for (char c : s) {
            str += "#";
            str += c;
        }
        str += "#$";

        int len = str.length();
        vector<int> p(len, 0);
        int iMax = 0, rMax = 0;
        int ans = 0;
        for (int i = 1; i < len - 1; ++i) {
            p[i] = (i <= rMax) ? min(rMax - i + 1, p[2 * iMax - i]) : 1;
            while (str[i + p[i]] == str[i - p[i]]) {
                p[i] += 1;
            }
            if (i + p[i] - 1 > rMax) {
                iMax = i;
                rMax = i + p[i] - 1;
            }
            ans += p[i] / 2;
        }
        return ans;
    }
};
// code_end

// 马拉车算法
class Solution2 {
public:
    int countSubstrings(string s) {
        string str = "^";
        for (char c : s) {
            str += "#";
            str += c;
        }
        str += "#$";
        int len = str.length();
        int iMax = 0, rMax = 0;
        vector<int> p(len, 0);

        int ans = 0;
        for (int i = 1; i < len - 1; ++i) {
            p[i] = (i <= rMax) ? min(rMax - i + 1, p[2 * iMax - i]) : 1;
            while (str[i + p[i]] == str[i - p[i]]) {
                p[i] += 1;
            }
            if (p[i] + i - 1 > rMax) {
                iMax = i;
                rMax = i + p[i] - 1;
            }
            ans += p[i] / 2;
        }
        return ans;
    }
};

// 中心拓展
class Solution1 {
public:
    int countSubstrings(string s) {
        int ans = 0;
        int len = s.length();

        for (int i = 0; i < 2 * len - 1; ++i) {
            int left = i / 2;
            int right = left + (i % 2);

            while (left >= 0 && right < len && s[left] == s[right]) {
                ans++;
                left--, right++;
            }
        }

        return ans;
    }
};

class mySolution {
public:
    int countSubstrings(string s) {
        int ans = 0;
        int dp[1000][1000] = {0};
        int len = s.length();
        for (int i = 0; i < len; ++i)
            dp[i][i] = 1;
        ans += len;

        for (int i = 1; i < len; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (s[i] == s[j] && (i - j <= 1 || dp[i - 1][j + 1] != 0))
                    dp[i][j] += 1;
                ans += dp[i][j];
            }
        }

        return ans;
    }
};



int main() {
    Solution solution;
    string s = "fdsklf";

    cout << solution.countSubstrings(s) << endl;
}
