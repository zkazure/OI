#include <bits/stdc++.h>
using namespace std;

// code_start

class Solution {
private:
    void swap(int &a, int &b) {
        int tmp = a;
        a = b;
        b = tmp;
    }
    vector<vector<int>> ans;
    
    void traversal(vector<int> &nums, int n) {
        if (n == nums.size()) {
            ans.push_back(nums);
            return ;
        }
        for (int i=n; i<nums.size(); ++i) {
            swap(nums[i], nums[n]);
            traversal(nums, n+1);
            swap(nums[i], nums[n]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        traversal(nums, 0);
        return ans;
    }
};

// code_end

class Solution1 {
private:
    vector<vector<int>> ans;
    vector<int> path;
    unordered_set<int> uset;
    void traversal(const vector<int> &nums) {
        if (uset.size() == nums.size()) {
            ans.push_back(path);
            return ;
        }
        for (auto n : nums) {
            if (uset.find(n) == uset.end()) {
                uset.insert(n);
                path.push_back(n);
                traversal(nums);
                uset.erase(n);
                path.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        traversal(nums);
        return ans;
    }
};


class Solution2 {
private:
    vector<vector<int>> ans;
    vector<int> path;
    
    void traversal(const vector<int> &nums, vector<bool> &used) {
        if (path.size() == nums.size()) {
            ans.push_back(path);
            return ;
        }
        for (int i=0; i<nums.size(); ++i) {
            if (used[i] == false) {
                used[i] = true;
                path.push_back(nums[i]);
                traversal(nums, used);
                path.pop_back();
                used[i] = false;
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        traversal(nums, used);
        return ans;
    }
};
