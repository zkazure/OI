#include <bits/stdc++.h>
using namespace std;

// code_start

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> m;
        for (int num : nums) {
            if (m.find(num)!=m.end()) 
                m[num]++;
            else m[num] = 1;
        }
        for (int i=0; i<k; ++i)
    }
};

// code_end

