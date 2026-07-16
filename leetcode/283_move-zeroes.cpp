#include <bits/stdc++.h>
using namespace std;

// code_start

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int i=0; i<nums.size()-1; i++) {
            for (int j=0; j<nums.size()-i-1; j++) {
                while(!nums[j] && nums[j+1])
                    swap(nums[j], nums[j+1]);
            }
        }
    }
};

// code_end

// above is the bubble sorting solution
// now let make a two pointer solution

class Solution2 {
public:
    void moveZeroes(vector<int>& nums) {
        int j=0;
        for (int i=0; i<nums.size(); i++) { // must start from 0, avoid changing consequence. 
            if (nums[i]) {
                swap(nums[i], nums[j]);
                j++;                
            }
        }
    }
};

int main () {
    vector<int> test1 = {0,1,0,3,12};
}

    
