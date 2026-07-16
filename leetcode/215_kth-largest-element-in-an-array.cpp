#include <bits/stdc++.h>
using namespace std; 

// code_start

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int c[20001] = {0};
        for (int i=0; i<nums.size(); i++) {
            c[nums[i]+10000]++;
        }

        int index = 20000;
        while (k>0) {
            k -= c[index];
            index--;
        }

        return index+1-10000;
    }
};

// code_end

int main() {
    vector<int> test = {3,2,3,1,2,4,5,5,6,7,7,8,2,3,1,1,1,10,11,5,6,2,4,7,8,5,6};
    Solution solution;
    int ans = solution.findKthLargest(test, 20);
}
