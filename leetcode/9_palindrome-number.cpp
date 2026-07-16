

// code_start

/*
  problem is easy, but it can be optimized much more.
  notice the example:
    1. no negative
    2. no end with 0
  the most important is that you can just compare half
    1. easy for even digit
    2. odd digit need to specify
  finally check the edge condition 0
*/

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x!=0 && x%10==0)) {
            return false;
        }

        int half = 0;
        while (x>half) {
            half = half*10 + x%10;
            x/=10;
        }
        return x == half or x == half / 10;
    }
};

// code_end

