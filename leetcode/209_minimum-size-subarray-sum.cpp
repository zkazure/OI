#include <bits/stdc++.h>
using namespace std;

// code_start

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum=0;
        int min_len=nums.size()+1;

        int l=0, r =0;
        for (; l<nums.size(); l++) {
            for (; r<nums.size() && sum<target; r++) {
                sum += nums[r];
            }
            if (sum >= target)
                min_len = min(min_len, r-l);
            if (r>=nums.size() && sum<target) {
                break;
            }
            sum -= nums[l];
        }
        if (min_len > nums.size())
            return 0;
        return min_len;
    }
};

// code_end

class Solution2 {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        long long sum=0;
        int min_len=nums.size()+1;

        for (int l=0; l<nums.size(); ++l) {
            sum=0;
            for (int r=l; r<nums.size(); ++r) {
                sum += nums[r];
                if (sum >= target) {
                    min_len = min(min_len, r-l+1);
                    break;
                }
            }
        }

        if (min_len>nums.size())
            return 0;
        
        return min_len;
    }
};

int main() {
    Solution s;
    int target = 7;
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    s.minSubArrayLen(target, nums);
}
