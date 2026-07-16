#include <bits/stdc++.h>
using namespace std;

// code_start

class Solution {
private:
    vector<vector<int>> ans;
    vector<int> path;
    void traversal(int n, int k, int idx) {
        if (path.size() == k) {
            ans.push_back(path);
            return ;
        }
        for (int i=idx; i<=n+path.size()-k+1; i+=1) {
            path.push_back(i);
            traversal(n, k, i+1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        traversal(n, k, 1);
        return ans;
    }
};

// code_end

