#include <bits/stdc++.h>
using namespace std;

// code_start

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> results;
        for (int i = 0; i < numRows; ++i) {
            vector<int> res;
            res.push_back(1);
            for (int j = 1; j < i; ++j) {
                res.push_back(results[i - 1][j - 1] + results[i - 1][j]);
            }
            if (i > 0) res.push_back(1);
            results.push_back(res);
        }
        return results;
    }
};

// code_end
