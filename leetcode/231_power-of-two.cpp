

// code_start

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n<=0) return false;

        return (n & (n-1)) == 0;
        
    }
};

// code_end

class Solution1 {
public:
    bool isPowerOfTwo(int n) {
        if (n==1) return true;

        switch (n%10) {
        case 2: ;
        case 4: ;
        case 8: ;
        case 6: break;
        default: return false;
        }
        
        return isPowerOfTwo(n/2);
    }
};
class Solution2 {
public:
    bool isPowerOfTwo(int n) {
        if (n==1) return true;

        switch (n%10) {
        case 2: ;
        case 4: ;
        case 8: ;
        case 6: break;
        default: return false;
        }
        
        while (n != 1) {
            if (n%2 != 0) return false;
            n /= 2;
        }

        return true;
    }
};
