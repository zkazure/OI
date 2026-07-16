#include <bits/stdc++.h>
using namespace std;

// code_start

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        for (int i=0; ; i++) {
            char c;
            if (i < strs[0].size()) c = strs[0][i];
            else return ans;
            
            for (int j=1; j<strs.size(); ++j) {
                if (i >= strs[j].size()) return ans;

                if (strs[j][i] != c) return ans;
            }

            ans += strs[0][i];
        }
        
        return ans;
    }

};

// code_end

