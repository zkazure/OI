#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// code_start

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> umap;
        for (const int a : nums1) {
            for (const int b: nums2) {
                umap[a+b] ++;
            }
        }

        int cnt = 0;
        for (const int c : nums3) {
            for (const int d : nums4) {
                if (umap.find(-c-d) != umap.end())
                    cnt += umap[-c-d];
            }
        }

        return cnt;
    }
};

// code_end

