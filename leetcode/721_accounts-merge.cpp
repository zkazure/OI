#include <bits/stdc++.h>
using namespace std;

// code_start

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, vector<string>> graph;
        unordered_map<string, string> email2name;
        for (const auto &account : accounts) {
            string firstEmail = account[1];
            email2name[firstEmail] = account[0];
            for (int i = 2; i < account.size(); ++i) {
                graph[firstEmail].push_back(account[i]);
                graph[account[i]].push_back(firstEmail);
                email2name[account[i]] = account[0];
            }
        }


        vector<vector<string>> merged;
        unordered_set<string> visited;
        for (const auto &pair : email2name) {
            string email = pair.first;
            if (visited.find(email) == visited.end()) {
                vector<string> emails;
                dfs(graph, emails, visited, email);
                sort(emails.begin(), emails.end());
                vector<string> tmp;
                tmp.push_back(email2name[email]);
                tmp.insert(tmp.end(), emails.begin(), emails.end());
                merged.push_back(tmp);
            }
        }

        return merged;
    }
    void dfs(unordered_map<string, vector<string>> &graph,
             vector<string> &emails,
             unordered_set<string> &visited, const string &email) {
        visited.insert(email);
        emails.push_back(email);
        for (const string &ee : graph[email]) {
            if (visited.find(ee) == visited.end()) {
                dfs(graph, emails, visited, ee);
            }
        }
    }
};

// code_end
