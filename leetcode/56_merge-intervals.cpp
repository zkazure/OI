#include <bits/stdc++.h>
using namespace std;

// code_start

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end(),
             [](const vector<int> &a, const vector<int> &b) {
                 return a[0] < b[0];
             });
        int start = intervals[0][0], end = intervals[0][1];
        for (int i=1; i<intervals.size(); ++i) {
            if (end >= intervals[i][0]) {
                end = max(end, intervals[i][1]);
            } else {
                ans.push_back( {start, end} );
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        ans.push_back({start, end});

        return ans;
    }
};

// code_end

