#include <bits/stdc++.h>
#include <vector>
using namespace std;

// code_start

class Solution {
private:
    vector<vector<int>> ans;
    vector<int> path;
    void traversal(vector<int> &candidates, int target, int sum, int idx) {
        if (sum > target) {
            return ;
        } else if (sum == target) {
            ans.push_back(path);
            return ;
        }
        for (int i=idx; i<candidates.size(); i+=1) {
            if (i>idx && candidates[i]==candidates[i-1]) {
                continue;
            }
            path.push_back(candidates[i]);
            traversal(candidates, target, sum+candidates[i], i+1);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        traversal(candidates, target, 0, 0);
        return ans;
    }
};

// code_end

class Solution1 {
private:
    vector<vector<int>> ans;
    vector<int> path;
    void traversal(vector<int> &candidates, int target, int sum, int idx, vector<bool> &used) {
        if (sum > target) {
            return ;
        } else if (sum == target) {
            ans.push_back(path);
            return ;
        }
        for (int i=idx; i<candidates.size(); i+=1) {
            if (i>0 && candidates[i]==candidates[i-1] && used[i-1]==false) {
                continue;
            }
            path.push_back(candidates[i]);
            used[i] = true;
            traversal(candidates, target, sum+candidates[i], i+1, used);
            used[i] = false;
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<bool> used(candidates.size(), false);
        sort(candidates.begin(), candidates.end());
        traversal(candidates, target, 0, 0, used);
        return ans;
    }
};
