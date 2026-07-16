#include <bits/stdc++.h>
using namespace std;

// code_start

class Solution {
private:
    set<vector<int>> ans;
    vector<int> path;

    void traversal(const vector<int> &nums, int idx) {
        if (idx>=nums.size()) {
            if (path.size()>=2) {
                ans.insert(path);
            }
            return;
        }

        if (!path.size() || nums[idx]>=path.back()) {
            path.push_back(nums[idx]);
            traversal(nums, idx+1);
            path.pop_back();
        }
        traversal(nums, idx+1);
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        traversal(nums, 0);
        return vector(ans.begin(), ans.end());
    }
};

// code_end

class Solution1 {
private:
    vector<vector<int>> ans;
    vector<int> path;

    void traversal(const vector<int> &nums, int idx) {
        if (path.size() > 1) {
            ans.push_back(path);
        }
        unordered_set<int> uset;
        for (int i=idx; i<nums.size(); ++i) {
            if ( (path.empty() || nums[i]>=path.back()) && uset.find(nums[i])==uset.end()) {
                uset.insert(nums[i]);
                path.push_back(nums[i]);
                traversal(nums, i+1);
                path.pop_back();
            }
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        traversal(nums, 0);
        return ans;
    }
};
