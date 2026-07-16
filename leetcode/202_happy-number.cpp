#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

// code_start

class Solution {
public:
    int getSum(int n) {
        int sum = 0;
        while (n) {
            sum += (n%10) * (n%10);
            n /= 10;
        }
        return sum;
    }
    
    bool isHappy(int n) {
        unordered_set<int> results;

        while (true) {
            n = getSum(n);
            if (n==1)
                return true;
            else if (results.find(n) != results.end())
                return false;
            else results.insert(n);
        }
    }
};

// code_end

