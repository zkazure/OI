#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

// code_start

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> results;
        unordered_set<int> nums(nums1.begin(), nums1.end());
        for (const int n : nums2) {
            if (nums.find(n) != nums.end())
                results.insert(n);
        }
        return vector<int>(results.begin(), results.end());
    }
};

// code_end

