#include <bits/stdc++.h>
using namespace std;

// code_start

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        for (int i=1; i<prices.size(); ++i) {
            int prof = prices[i] - prices[i-1];
            if (prof > 0) {
                ans += prof;
            }
        }

        return ans;
    }
};

// code_end

