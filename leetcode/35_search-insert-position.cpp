#include <vector>
using namespace std;

// code_start

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left=0, right=nums.size()-1;
        int mid;
        while (right >= left) {
            mid = left + ( (right-left)>>1 );
            if (target < nums[mid])
                right = mid-1;
            else if (nums[mid] < target)
                left = mid+1;
            else return mid;
        }

        return left;
    }
};

// code_end

