#include <bits/stdc++.h>
using namespace std;

// code_start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left=0;
        for (int right=0; right<nums.size(); right++) {
            if (nums[right] != val)
                nums[left++] = nums[right];
        }

        return left;
    }
};


// code_end


// most common solution
class Solution2 {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            if (nums[i] == val) {
                for (int j = i + 1; j < size; j++) {
                    nums[j - 1] = nums[j];
                }
                i--;
                size--;
            }
        }
        return size;
    }
};
