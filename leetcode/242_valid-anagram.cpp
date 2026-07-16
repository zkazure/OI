#include <bits/stdc++.h>
using namespace std;

// code_start

class Solution {
public:
    bool isAnagram(string s, string t) {
        int a[26] = {0};
        for (const char c : s)
            a[c-'a']++;
        for (const char c : t)
            a[c-'a']--;

        for (int v : a)
            if (v!=0)
                return false;

        return true;
    }
};

// code_end

