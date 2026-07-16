#include <bits/stdc++.h>
using namespace std;

// code_start

class Solution {
public:
  bool canPartition(vector<int> &nums) {
    int sum = 0;
    for (auto num : nums) {
      sum += num;
    }
    if (sum % 2 == 1)
      return false;

    int target = sum / 2;
    int dp[10001] = {0};
    for (int i = 0; i < nums.size(); ++i) {
      for (int j = target; j >= nums[i]; --j) {
        dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
      }
    }

    if (dp[target] == target)
      return true;

    return false;
  }
};

// code_end

int main() {
  Solution s;
  vector<int> test = {1, 5, 11, 5};
  s.canPartition(test);
}
