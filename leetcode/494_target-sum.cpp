#include <bits/stdc++.h>
using namespace std;

// code_start

class Solution {
public:
  int findTargetSumWays(vector<int> &nums, int target) {
    int sum = 0;
    for (int num : nums) {
      sum += num;
    }
    if (abs(target) > sum)
      return 0;
    if ((sum - target) % 2 == 1)
      return 0;

    int ans = 0;
    int aim = (sum + target) / 2;
    int dp[10001] = {0};
    dp[0] = 1;
    for (int i = 0; i < nums.size(); ++i) {
      for (int j = aim; j >= nums[i]; --j) {
        dp[j] += dp[j - nums[i]];
      }
    }
    return dp[aim];
  }
};

// code_end

int main() {
  Solution s;
  vector<int> test = {1, 1, 1, 1, 1};
  int target = 3;
  s.findTargetSumWays(test, target);
}
