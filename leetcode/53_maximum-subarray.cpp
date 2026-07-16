#include <bits/stdc++.h>
using namespace std;

// code_start

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT32_MIN;
        int sum = 0;
        for (auto num : nums) {
            sum += num;
            if (sum > ans) {
                ans = sum;
            }
            if (sum < 0) {
                sum = 0;
            }
        }

        return ans;
    }
};

// code_end

