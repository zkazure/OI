#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

// code_start

class Solution {
private:
    vector<vector<int>> ans;
    void traversal(vector<int> &nums, int k) {
        if (k == nums.size()) {
            ans.push_back(nums);
            return ;
        }
        unordered_set<int> uset;
        for (int i=k; i<nums.size(); ++i) {
            if (uset.find(nums[i]) == uset.end()) {
                swap(nums[i], nums[k]);
                traversal(nums, k+1);
                swap(nums[i], nums[k]);                
                uset.insert(nums[i]);
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        traversal(nums, 0);
        return ans;
    }
};

// code_end

