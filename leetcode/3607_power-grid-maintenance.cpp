#include <bits/stdc++.h>
using namespace std;

// code_start

class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<int> ans;
        int stations[c+1]; memset(stations, 1, sizeof(stations));
        int power[c+1][c+1]; memset(power, 0, sizeof(power));
        for (auto connection : connections) {
            power[connection[0]][connection[1]] = 1;
            // power[connection[1]][connection[0]] = 1;
        }

        for (auto query : queries) {
            if (query[0] == 1) {
                if (stations[query[1]]) ans.push_back(query[1]);
                else {
                    
                }
            } else {
                stations[query[1]] = 0;
            }
        }

        return ans;
    }

    
};

// code_end

