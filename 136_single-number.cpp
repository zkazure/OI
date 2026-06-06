#include <bits/stdc++.h>
using namespace std;

// code_start

// 异或的思路真的很神奇
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (const int &n : nums) {
            ans ^= n;
        }
        return ans;
    }
};

class Solution1 {
public:
    int singleNumber(vector<int>& nums) {
        const int N = 30000;
        int marked[2 * N + 1] = {0};
        for (const int &n : nums) {
            marked[n + N] = !marked[n + N];
        }
        for (const int &n : nums) {
            if (marked[n + N])
                return n;
        }
        return 0;
    }
};

// code_end
