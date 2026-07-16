#include <bits/stdc++.h>
using namespace std;

// code_start

class Solution {
private:
    vector<vector<string>> ans;
    vector<string> path;
    void traversal(const string &s, int idx) {
        if (idx >= s.size()) {
            ans.push_back(path);
            return ;
        }
        for (int i=idx; i<s.size(); i+=1) {
            bool pali = true;
            for (int j=0; j<=(i-idx)/2; j+=1) {
                if (s[i-j] != s[idx+j]) {
                    pali = false;
                    break;
                }
            }
            // for (int j=idx, k=i; j<k; j+=1, k-=1) {
            //     if (s[j] != s[k]) {
            //         pali = false;
            //         break;
            //     }
            // }
            if (pali == false) continue;
            path.push_back(s.substr(idx, i-idx+1));
            traversal(s, i+1);
            path.pop_back();
        }
    }
public:
    vector<vector<string>> partition(string s) {
        traversal(s, 0);
        return ans;
    }
};

// code_end

int main() {
    Solution s;
    s.partition("aab");
}
