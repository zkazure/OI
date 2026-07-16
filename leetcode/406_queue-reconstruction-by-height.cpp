#include <bits/stdc++.h>
using namespace std;

// code_start

class Solution {
private:
    struct {
        bool operator()(vector<int> a, vector<int> b) {
            if (a[0] == b[0]) return a[1] < b[1];
            return a[0] > b[0];
        }
    } customLess;
    
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> ans;
        sort(people.begin(), people.end(), customLess);
        for (int i=0; i<people.size(); ++i) {
            ans.insert(ans.begin()+people[i][1], people[i]);
        }

        return ans;
    }
};

// code_end

