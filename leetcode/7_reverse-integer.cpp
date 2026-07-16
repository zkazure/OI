#include <bits/stdc++.h>
using namespace std; 

// code_start

class Solution {
public:
    int reverse(int x) {
        int ret = 0;
        while (x != 0) {
            // if (x>0 && ret>(INT_MAX-x%10)/10)
            //     return 0;
            // else if (x<0 && ret<(INT_MIN-x%10)/10)
            //     return 0;
            // 最后 +10 也不可能溢出
            if (ret>INT_MAX/10 || ret<INT_MIN/10)
                return 0;
            
            ret = ret*10 + x%10;
            x /= 10;
        }

        return ret;
    }
};

// code_end

