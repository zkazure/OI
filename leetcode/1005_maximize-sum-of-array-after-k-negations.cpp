#include <bits/stdc++.h>
using namespace std;

// code_start

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int min_num = abs(nums[0]);
        for (auto num : nums) {
            min_num = min(abs(num), min_num);
            if (num<0 && k>0) {
                ans -= num;
                k -= 1;
            } else {
                ans += num;
            }
        }
        if (k%2==1) {
            ans -= 2*min_num;
        }
        
        return ans;
    }
};

// code_end

