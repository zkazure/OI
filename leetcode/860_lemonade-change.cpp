#include <bits/stdc++.h>
using namespace std;

// code_start

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int change[3] = {0};
        for (int bill : bills) {
            if (bill == 5) change[0] += 1;
            else if (bill == 10) change[1] += 1;
            else change[2] += 1;

            int to_change = bill - 5;
            if (to_change >= 20) {
                int tmp = to_change / 20;
                if (tmp > change[2]) {
                    tmp = change[2];
                }
                change[2] -= tmp;
                to_change -= 20 * tmp;
            }
            if (to_change >= 10) {
                int tmp = to_change / 10;
                if (tmp > change[1]) {
                    tmp = change[1];
                }
                change[1] -= tmp;
                to_change -= 10 * tmp;
            }
            if (to_change >= 5) {
                int tmp = to_change / 5;
                if (tmp > change[0]) {
                    tmp = change[0];
                }
                change[0] -= tmp;
                to_change -= 5 * tmp;
            }
            if (to_change > 0) {
                return false;
            }
        }
        return true;
    }
};

// code_end

