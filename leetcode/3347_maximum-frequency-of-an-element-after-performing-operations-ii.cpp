#include <bits/stdc++.h>
using namespace std;

// code_start

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int ans = 1;
        sort(nums.begin(), nums.end());

        // if (numOperations == 0) {
        //     int freq = 1;
        //     for (int i=1; i<nums.size(); ++i) {
        //         if (nums[i] != nums[i-1]) {
        //             ans = max(freq, ans);
        //             freq = 1;
        //             continue;
        //         }
        //         freq += 1;
        //     }
        //     ans = max(freq, ans);
        //     return ans;
        // }
        
        for (int i=nums[0]-k; i<=nums[nums.size()-1]+k; ++i) {
            int freq = 0;
            int oper = numOperations;
            for (int j=0; oper>=0 && j<nums.size(); ++j) {
                if (oper == 0) {
                    if (i == nums[j]) freq += 1;
                    continue;
                }
                if (i > nums[j]+k) continue;
                if (i < nums[j]-k) {
                    i = nums[j]-k-1;
                    break;
                }
                if (i != nums[j]) oper -= 1;
                freq += 1;
            }
            ans = max(freq, ans);
        }

        return ans;
    }
};

// code_end

int main() {
    Solution s;
    // vector<int> nums = {68, 120, 120, 36};
    // int k = 99;
    // int numOperations = 2;

    vector<int> nums = {39,2,17,82,25,2};
    int k = 14;
    int numOperations = 2;
    
    int test_ans = s.maxFrequency(nums, k, numOperations);

    return 0;
}
