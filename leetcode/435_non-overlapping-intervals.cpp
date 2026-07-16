#include <bits/stdc++.h>
using namespace std;

// code_start

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans = 0;
        sort(intervals.begin(), intervals.end(),
             [](const vector<int> &a, const vector<int> &b)
             {
                 if (a[0] != b[0]) return a[0] < b[0];
                 return a[1] < b[1];
             });
        int left = intervals[0][0];
        int right = intervals[0][1];

        for (int i=1; i<intervals.size(); i++) {
            if (right > intervals[i][0]) {
                ans ++;
                left = intervals[i][0];
                right = right>intervals[i][1] ? intervals[i][1] : right;
            } else {
                left = intervals[i][0];
                right = intervals[i][1];
            }            
        }
        return ans;
    }
};

// code_end

