#include <bits/stdc++.h>
using namespace std;

// code_start

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        vector<int> prefix(s.size(), 0);
        for (int i=1; i<s.size(); ++i) {
            int len = prefix[i-1];
            while (len!=0 && s[len]!=s[i])
                len = prefix[len-1];
            if (s[len] == s[i]) {
                prefix[i] = len+1;
            }
        }

        int a=prefix[s.size()-1], b=s.size();
        int c=b-a;
        if (a!=0 && a%c==0)
            return true;
        return false;
    }
};

// code_end

