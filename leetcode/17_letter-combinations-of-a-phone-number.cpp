#include <bits/stdc++.h>
using namespace std;

// code_start

class Solution {
private:
    const vector<string> tele = {"", "",
                                 "abc", "def", "ghi", "jkl",
                                 "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;
    string path;
    void traversal(int idx, const string &digits) {
        if (idx == digits.size()) {
            ans.push_back(path);
            return ;
        }

        int num = digits[idx] - '0';
        for (int i=0; i<tele[num].size(); i+=1) {
            path += tele[num][i];
            traversal(idx+1, digits);
            path.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        traversal(0, digits);

        return ans;
    }
};

// code_end

