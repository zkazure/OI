#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// code_start

class Solution {
private:
    unordered_map<char, int> map = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
                                    {'C', 100}, {'D', 500}, {'M', 1000}};
public:
    int romanToInt(string s) {
        int ans = 0;
        for (int i=0; i<s.size()-1; ++i) {
            if (map[s[i]]<map[s[i+1]]) ans -= map[s[i]];
            else ans += map[s[i]];
        }
        
        return ans + map[s[s.size()-1]];
    }
};

// code_end

// my solution
class Solution1 {
private:
    unordered_map<char, int> map = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
                                    {'C', 100}, {'D', 500}, {'M', 1000}};
public:
    int romanToInt(string s) {
        int ans = 0;
        for (int i=0; i<s.size(); ++i) {
            if (i == s.size()) {
                ans += map[s[i]];
                break;
            }
            if (map[s[i]]<map[s[i+1]]) ans -= map[s[i]];
            else ans += map[s[i]];
        }
        return ans;
    }
};
