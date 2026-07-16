#include <bits/stdc++.h>
using namespace std;

// code_start

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        if (nums.size()<2)
            return nums;
        
        int c[100001] = {0};
        for (int i=0; i<nums.size(); ++i)
            c[nums[i]+50000]++;
        int index = 0;
        for (int i=0; i<100001; i++) {
            int tmp = c[i];
            for (int j=0; j<tmp; ++j) {
                nums[index++] = i-50000;
            }
        }
        return nums;
    }
};

// code_end

