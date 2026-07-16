#include <bits/stdc++.h>
#include <unordered_map>
using namespace std; 

// code_start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for (int i=0; i<nums.size(); i++) {
            auto iter = map.find(target - nums[i]);
            if (iter != map.end())
                return {iter->second, i};
            else map.insert(pair<int, int>(nums[i], i));
        }
        return {};
    }
};

// code_end

class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans; 
        for (int i=0; i<nums.size()-1; ++i) {
            for (int j=i+1; j<nums.size(); ++j) {
                if (nums[i]+nums[j]==target) {
                    ans.push_back(i);
                    ans.push_back(j);
                    break;
                }
            }
        }
        return ans;
    }
};

