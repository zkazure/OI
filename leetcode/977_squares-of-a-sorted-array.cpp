#include <bits/stdc++.h>
using namespace std;

// code_start

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        int l=0, r=nums.size()-1;
        for (int i=r; i>=0; --i) {
            if (nums[l]+nums[r]>0) {
                ans[i] = nums[r]*nums[r];
                r--;
            } else {
                ans[i] = nums[l]*nums[l];
                l++;
            }
        }

        return ans;
    }
};

// code_end

