#include <bits/stdc++.h>
using namespace std;

// code_start

class Solution {
private:
    vector<vector<int>> ans;
    vector<int> path;
    void traversal(const vector<int> &nums, int idx) {
        ans.push_back(path);
        for (int i=idx; i<nums.size(); ++i) {
            if (i>idx && nums[i]==nums[i-1]) continue;
            path.push_back(nums[i]);
            traversal(nums, i+1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        // ans.push_back(vector<int>());
        traversal(nums, 0);
        return ans;
    }
};

// code_end

