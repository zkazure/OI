#include <bits/stdc++.h> 
using namespace std;

// code_start

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        const int N = 1001;
        vector<int> ans;
        int c[N] = {0};

        for (int i=0; i<arr1.size(); i++) {
            c[arr1[i]]++;
        }

        for (int i=0; i<arr2.size(); i++) {
            while (c[arr2[i]]) {
                ans.push_back(arr2[i]);
                c[arr2[i]]--;
            }
        }
        // for (int i=0; i<arr1.size(); i++) {
        //     for (int j=0; j<c[arr1[i]]; j++)
        //         ans.push_back(arr1[i]);
        // }
        for (int i=0; i<N; i++) {
            for (int j=0; j<c[i]; ++j) {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};

// code_end

