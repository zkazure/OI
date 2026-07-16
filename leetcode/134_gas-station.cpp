#include <bits/stdc++.h>
using namespace std;

// code_start

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0;
        int total = 0;
        int curr = 0;
        for (int i=0; i<gas.size(); ++i) {
            total = total + gas[i] - cost[i];
            curr = curr + gas[i] - cost[i];
            if (curr < 0) {
                start = i+1;
                curr = 0;
            }
        }
        if (total < 0) {
            return -1;
        }
        return start;
    }
};

// code_end

int main() {
    Solution s;
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};
    s.canCompleteCircuit(gas, cost);
}
