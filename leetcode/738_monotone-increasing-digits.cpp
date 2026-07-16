#include <bits/stdc++.h>
using namespace std;

// code_start

class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string strNum = to_string(n);
        int flag = strNum.size();
        for (int i=strNum.size()-1; i>0; --i) {
            if (strNum[i-1] > strNum[i]) {
                flag = i;
                strNum[i-1] --;
            }
        }
        for (int i=flag; i<strNum.size(); ++i) {
            strNum[i] = '9';
        }
        return stoi(strNum);
    }
};

// code_end

class Solution1 {
public:
    int monotoneIncreasingDigits(int n) {
        if (n == 0) return 0;
        
        vector<int> digits;
        while (n > 0) {
            digits.push_back(n%10);
            n /= 10;
        }
        
        int ans = digits[0];
        for (int i=1; i<digits.size(); ++i) {
            if (digits[i-1] >= digits[i]) {
                int tmp = 1;
                for (int j=i; j>0; j--) {
                    tmp *= 10;
                }                
                ans += digits[i] * tmp;
            } else {
                int tmp = digits[i];
                for (int j=i; j>0; j--) {
                    tmp *= 10;
                }
                digits[i] -= 1;
                for (int j=i-1; j>=0; --j) {
                    digits[j] = 9;
                }
                ans = tmp - 1;
            }
        }

        return ans;
    }
};
