#include <bits/stdc++.h>
#include <set>
using namespace std;

// code_start

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        multiset<int, greater<int>> window;

        int slow=0, fast=0;
        while (fast < nums.size()) {
            while (slow+k-1 >= fast) {
                window.insert(nums[fast++]);
            }
            ans.push_back(*window.begin());

            window.erase(window.find(nums[slow++]));
        }
        return ans;
    }

};

// code_end

class Solution2 {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        
        int tmp = nums[0];
        int slow = 0, fast = 0;
        for (fast=0; fast<k; fast++)
            tmp = max(nums[fast], tmp);
        fast--;
        ans.push_back(tmp);
        fast++, slow++;
        
        while (fast < nums.size()) {
            if (nums[slow-1]==tmp) {
                int last_max = tmp;
                tmp = -10000;
                for (int i=slow; i<=fast; ++i) {
                    tmp = max(tmp, nums[i]);                        
                    if (tmp==last_max)
                        break;
                }

            } else tmp = max(tmp, nums[fast]);
            
            ans.push_back(tmp);
            fast++, slow++;
        }
        return ans;
    }
};

int main() {
    // vector<int> test = {1, 3, -1, -3, 5, 3, 6, 7};
    vector<int> test = {1, 3, 1, 2, 0, 5};    
    Solution s;
    vector<int> ans = s.maxSlidingWindow(test, 3);

    return 0;
}
