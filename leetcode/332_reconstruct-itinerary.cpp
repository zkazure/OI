#include <bits/stdc++.h>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

// code_start

class Solution {
private:
    vector<string> ans;
    unordered_map<string, multiset<string>> umap;
    void traversal(string airport) {
        while (umap.size() > 0) {
            string next = *umap[airport].begin();
            umap[airport].erase(umap[airport].begin());
        }
        ans.push_back(airport);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto ticket : tickets) {
            umap[ticket[0]].insert(ticket[1]);
        }
        traversal("JFK");
        return vector<string>(ans.rbegin(), ans.rend());
    }
};

// code_end

int main() {
    Solution s;

    // vector<vector<string>> tickets = { {"MUC", "LHR"}, {"JFK", "MUC"},
    //                                    {"SFO", "JSC"}, {"LHR", "SFO"}};
    vector<vector<string>> tickets = { {"JFK", "SFO"}, {"JFK", "ATL"},
                                       {"SFO", "ATL"}, {"ATL", "JFK"},
                                       {"ATL", "SFO"}};    
    // cout << tickets.size();
    vector<string> ans = s.findItinerary(tickets);
    for (auto a : ans) {
        cout << a << "\n";
    }
}
