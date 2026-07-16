#include <bits/stdc++.h>
using namespace std;

// code_start

class Solution {
public:
    int integerBreak(int n) {
        int dp[60]={0};
        dp[1]=1;
        for (int i=2; i<n; i++) {
            dp[i] = i;
            int tmp = 0;
            for (int j=1; j<=i-j; ++j) {
                tmp = dp[j]*dp[i-j];
                dp[i] = std::max(dp[i], tmp);
            }
        }

        for (int i=1; i<=n-i; ++i) {
            dp[n] = max(dp[n], dp[i]*dp[n-i]);
        }
        return dp[n];
    }
};

// code_end

int main() {
    int test = 10;
    Solution s;
    cout << s.integerBreak(test);

    return 0;
}
