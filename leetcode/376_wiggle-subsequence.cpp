#include <bits/stdc++.h>
using namespace std;

// code_start

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        
        int ans = 1;
        int prediff=0, curdiff=0;
        for (int i=1; i<nums.size(); ++i) {
            curdiff = nums[i] - nums[i-1];
            if (prediff<=0&&curdiff>0 || prediff>=0&&curdiff<0) {
                ans += 1;
                prediff = curdiff;
            }
        }
        return ans;
    }
};

// code_end

