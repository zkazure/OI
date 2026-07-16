#include <bits/stdc++.h>
using namespace std;

// code_start

class Solution {
public:
  int rob(vector<int> &nums) {
    int dp[101];
    dp[0] = 0, dp[1] = nums[0];
    for (int i = 2; i <= nums.size(); ++i) {
      dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
    }
    return dp[nums.size()];
  }
};

// code_end

int main() {
  Solution s;
  vector<int> test = {2, 7, 9, 3, 1};
  s.rob(test);
}
