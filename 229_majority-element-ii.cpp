#include <bits/stdc++.h>
using namespace std;

// code_start

class Solution {
private:
    void cnt_dec(int &cnt) {
        if (cnt == 0) return;
        cnt -= 1;
    }
public:
    vector<int> majorityElement(vector<int>& nums) {
        if (nums.size() == 1) return nums;

        vector<int> cnts(2, 0);
        vector<int> cans(2, numeric_limits<int>::max());

        for (const auto &num : nums) {
            if (!cnts[0] && cans[1] != num) {
                cans[0] = num;
            } else if (!cnts[1] && cans[0] != num) {
                cans[1] = num;
            }


            if (num == cans[0]) cnts[0]++;
            else if (num == cans[1]) cnts[1]++;
            else cnts[0]--, cnts[1]--;
        }

        int low = nums.size() / 3;
        cnts[0] = 0; cnts[1] = 0;
        for (const auto &num : nums) {
            for (int i = 0; i < 2; ++i) {
                if (num == cans[i])
                    cnts[i]++;
            }
        }

        vector<int> res;
            for (int i = 0; i < 2; ++i) {
                if (cnts[i] > low)
                    res.push_back(cans[i]);
            }

        return res;
    }
};

// code_end
