#include <iostream>
#include <vector>
using namespace std;

// code_start

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        int index = n-1;
        for (; index>=0; index--) {
            if (digits[index] == 9) {
                digits[index] = 0;
            } else {
                break;
            }
        }
        
        if (index+1) {
            digits[index] ++;
            return digits;
        } else {
            vector<int> tmp(n+1, 0);
            tmp[0] = 1;
            return tmp;
        }
    }
};

// code_end

int main() {
    Solution s;
    vector<int> digits = {0};
    s.plusOne(digits);
}
