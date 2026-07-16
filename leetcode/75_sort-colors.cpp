#include <bits/stdc++.h>
#include <vector>
using namespace std;

// code_start

class Solution {
public:
    // the environment of leetcode have some problem
    // binary insertion sorting fail
    void sortColors(vector<int>& nums) {
        for (int i=1; i<nums.size(); i++) {
            if (nums[i] >= nums[i-1])
                continue;

            int left=0, right=i-1;
            int mid;
            int tmp = nums[i];
            do {
                mid = (left+right)/2;
                if (tmp >= nums[mid])
                    left = mid+1;
                else right = mid-1;
            } while (left <= right); 

            for (int j=i; j>mid; j--)
                nums[j] = nums[j-1];

            nums[mid] = tmp;
        }
    }
};

// code_end

// insert sorting, but change value rather than move
class Solution2 {
public:
    void sortColors(vector<int>& nums) {
        int p0=0, p1=0;
        int x;
        for (int i=0; i<nums.size(); ++i) {
            x = nums[i];
            nums[i] = 2;
            if (x<=1)
                nums[p1++] = 1;
            if (!x)
                nums[p0++] = 0;
        }
    }
};

// direct insertion sort
class Solution3 {
public:
    void sortColors(vector<int>& nums) {
        // this is the most common insertion sorrting. 
        for (int i=1; i<nums.size(); ++i) {
            int tmp = nums[i];
            int j=i-1;
            for(;j>=0 && nums[j]>tmp; j--) {
                nums[j+1] = nums[j];
            }
            nums[j+1] = tmp;
        }
    }
};

int main() {
    vector<int> test = {1,1,0,2,0,2};
    // vector<int>test = {1, 0, 2};
    // vector<int>test = {2, 0, 1};    
    Solution solution;
    solution.sortColors(test);

    return 0;
}
