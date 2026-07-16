#include <bits/stdc++.h>
using namespace std;

// code_start

class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() <= 1) return 0;
        int cover = 0;
        int pre_cover = 0;
        int ans = 0;
        for (int i=0; i<=cover; ++i) {
            cover = max(cover, i+nums[i]);
            if (i == pre_cover) {
                ans += 1;
                pre_cover = cover;
                if (pre_cover >= nums.size()-1) {
                    break;
                }
            }
        }
        return ans;
    }
};

// code_end

