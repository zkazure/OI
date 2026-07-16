#include <bits/stdc++.h>
using namespace std;

// code_start

class Solution {
private:
    vector<vector<int>> ans;
    vector<int> path;
    void traversal(vector<int> &nums, int idx) {
        for (int i=idx; i<nums.size(); ++i) {
            path.push_back(nums[i]);
            ans.push_back(path);
            traversal(nums, i+1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        ans.push_back(vector<int>());
        traversal(nums, 0);
        return ans;
    }
};

// code_end

