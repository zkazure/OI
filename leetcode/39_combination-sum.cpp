#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

// code_start

class Solution {
private:
    vector<vector<int>> ans;
    vector<int> path;
    void traversal(const vector<int>& candidates, int target, int sum, int idx) {
        if (sum > target) {
            return ;
        } else if (sum == target) {
            ans.push_back(path);
            return ;
        }
        for (int i=idx; i< candidates.size(); i+=1) {
            path.push_back(candidates[i]);
            traversal(candidates, target, sum+candidates[i], i);
            path.pop_back();
        }
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        traversal(candidates, target, 0, 0);
        return ans;
    }
};

// code_end

