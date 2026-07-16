#include <bits/stdc++.h>
using namespace std;

// code_start

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int a[26] = {0};
        for (const char c : magazine) {
            a[c-'a']++;
        }
        for (const char c : ransomNote) {
            a[c-'a']--;
        }
        for (int i=0; i<26; ++i) {
            if (a[i]<0)
                return false;
        }

        return true;
    }
};

// code_end

