#include <bits/stdc++.h>


// code_start
class Solution {
public:
    bool isPerfectSquare(int num) {
        int left=1, right=num;
        while (right>=left) {
            int mid = left+ ( (right-left) >> 1);
            double tmp = (double) num/mid;
            if (tmp > mid)
                left = mid+1;
            else if (tmp < mid)
                right = mid-1;
            else return true;
        }
        
        return false;
    }
};

// code_end

int main() {
    // std::cout << INT32_MAX;
    // 2147483647
    Solution s;
    bool a = s.isPerfectSquare(100000001);
}
