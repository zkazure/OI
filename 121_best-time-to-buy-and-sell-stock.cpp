#include <bits/stdc++.h>
using namespace std;

// code_start

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0, right = 0;
        int profit = 0;         // buy and sell on the same day, even do nothing

        for (int i = 1; i < prices.size(); ++i) {
            if (left > right || prices[i] >= prices[right]) {
                right = i;
                profit = max(profit, prices[right] - prices[left]);
            }

            if (prices[i] < prices[left]) {
                left = i;
            }
        }

        return profit;
    }
};

// code_end
