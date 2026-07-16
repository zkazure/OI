#include <climits>
#include <iostream>
// code_start

class Solution {
public:
    int mySqrt(int x) {
        if (!x) {
            return 0;
        }
        if(x==1) {
            return 1;
        }
        
        int up = x;
        int low = 0;
        int mid = 0;
        int div = 0;
        do {
            mid = (up+low)/2;
            div = x/mid;
            
            if (div == mid) { break; }
            
            if (div > mid) {
                low = mid;
            } else {
                up = mid;
            }
            mid = (up+low)/2;
            
            if (mid == low) { 
                break;
            }
            
        } while (1);
        

        return mid;
    }
};

// code_end

int main() {
    // std::cout << INT_MAX << std::endl;
    int factor = INT_MAX / 2;
    int a = INT_MAX;
    while (factor >= INT_MAX) {
        factor /=2;
        std::cout << factor << std::endl;        
    }
    
    return 0;
}
