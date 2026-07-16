#include <bits/stdc++.h>
using namespace std;

// code_start

class Solution {
private:
    vector<vector<int>> ans;
    vector<int> path;
    void traversal(int k, int n, int idx, int sum) {
        if (path.size() == k) {
            if (sum == n) {
                ans.push_back(path);                
            }
            return ;                
        }
        for (int i=idx; i<=10+path.size()-k; i+=1) {
            if (i <= n-sum) {
                path.push_back(i);
                traversal(k, n, i+1, sum+i);
                path.pop_back();                
            } else {
                break;
            }
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        traversal(k, n, 1, 0);
        return ans;
    }
};

// code_end

