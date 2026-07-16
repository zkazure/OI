#include <bits/stdc++.h>
using namespace std;

// code_start

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int can;
        for (const auto &num : nums) {
            if (cnt == 0) can = num;

            if (num == can) cnt++;
            else cnt--;
        }

        return can;
    }
};

// code_end
