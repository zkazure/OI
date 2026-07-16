#include <bits/stdc++.h>
using namespace std;

// code_star

class Solution {
private:
    bool isValid(string& s) {
        if (s.length() == 1) return true;
        if (s[0] == '0') return false;
        if (s.length() < 3) return true;
        if (s[0]>'2') return false;
        if (s[0]=='2' && s[1]>'5') return false;
        if (s[0]=='2' && s[1]=='5' && s[2]>'5') return false;
        return true;
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        for (int i=1; i<=3; ++i) {
            for (int j=1; j<=3; ++j) {
                for (int k=1; k<=3; ++k) {
                    if (i+j+k<s.length() && i+j+k+3>=s.length()) {
                        string a = s.substr(0, i);
                        string b = s.substr(i, j);
                        string c = s.substr(i+j, k);
                        string d = s.substr(i+j+k);
                        if (isValid(a) && isValid(b) && isValid(c) && isValid(d)) {
                            ans.push_back(a+"."+b+"."+c+"."+d);
                        }                        
                    }
                }
            }
        }

        return ans;
    }
};


// code_end


class Solution1 {
private:
    vector<string> ans;
    string path;
    void traversal(const string& s, int idx, int k) {
        if (k==5) return;
        if (idx==s.length() && k==4) {
            ans.push_back(path);
            return;
        }

        for (int i=idx; i<=idx+2 && i<s.length(); i++) {
            if (i>idx && s[idx]=='0') {
                break;
            }
            if (i-idx+1>=3 && s.substr(idx, i-idx+1) > "255") {
                break;
            }
            for (int j=idx; j<=i; ++j) {
                path.push_back(s[j]);
            }
            if (k < 3) {
                path.push_back('.');
            }
            traversal(s, i+1, k+1);
            if (k < 3) {
                path.pop_back();
            }
            for (int j=idx; j<=i; ++j) {
                path.pop_back();
            }
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        traversal(s, 0, 0);
        return ans;
    }
};

// int main() {
//     Solution s;
//     string test = "25525511135";
//     s.restoreIpAddresses(test);
//     return 0;
// }
