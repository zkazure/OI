#include <bits/stdc++.h>
using namespace std;

// code_start

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 0) return 0;
        int ans = 0;
        sort(points.begin(), points.end(),
             [](const vector<int> &a, const vector<int> &b)
             {
                 if (a[0] != b[0]) return a[0] < b[0];
                 return a[1] < b[1];
             });
        int left=points[0][0], right=points[0][1];
        for (auto point : points) {
            if (point[0] <= right) {
                // overlap
                left = point[0];
                right = right>point[1] ? point[1] : right;
            } else {
                // not overlap update
                ans++;
                left = point[0];
                right = point[1];
            }
        }
        
        return ans+1;           // shot the last balloon
    }
};

// code_end

