#include <iostream>
using namespace std;

// code_start

class Solution {
public:
    int fib(int n) {
        int dp[35];
        dp[0] = 0, dp[1] = 1;
        for (int i=2; i<=n; ++i) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};

// code_end

int main() {
    Solution s;
    cout << s.fib(3);
}
