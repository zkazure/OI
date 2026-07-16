#include <string>
#include <bits/stdc++.h>
using namespace std;

// code_start

class Solution {
public:
    int strStr(string haystack, string needle) {
        int ans = -1;
        string str = needle + "#" + haystack;
        vector<int> prefix(str.size(), 0);
        for (int i=1; i<str.size(); ++i) {
            int len = prefix[i-1];
            while (len!=0 && str[i]!=str[len])
                len = prefix[len-1];
            if (str[i] == str[len]) {
                prefix[i] = len+1;
                if (prefix[i] == needle.size()) {
                    ans = i+1 - needle.size() -1 -needle.size();
                    break;
                }
            }p
        }
        return ans;
    }
};

// code_end

