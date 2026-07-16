#include <bits/stdc++.h>
using namespace std;

// code_start

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cover = 0;
        for (int i=0; i<nums.size(); ++i) {
            if (i <= cover) {
                cover = max(cover, i+nums[i]);
                if (cover >= nums.size()-1) return true;
            }
        }
        return false;
    }
};

// code_end

class Solution1 {
public:
    bool canJump(vector<int>& nums) {
        bool dp[10005] = {true, false};
        for (int i=0; i<nums.size()-1; ++i) {
            if (dp[i]) {
                for (int j=1; j<=nums[i]; ++j) {
                    if (i+j < 10005) {
                        dp[i+j] = true;
                    }
                }                
            }
        }
        return dp[nums.size()-1];
    }
};
