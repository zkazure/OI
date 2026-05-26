#include <bits/stdc++.h>
using namespace std;

// code_start

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> paths;
        vector<int> path;
        path.reserve(graph.size());

        path.push_back(0);
        dfs(graph, paths, path, 0, graph.size() - 1);
        return paths;
    }
    void dfs(const vector<vector<int>> &graph,
             vector<vector<int>> &paths, vector<int> &path,
             int cur, int des) {
        if (cur == des) {
            paths.push_back(path);
            return;
        }
        for (int i = 0; i < graph[cur].size(); ++i) {
            path.push_back(graph[cur][i]);
            dfs(graph, paths, path,graph[cur][i], des);
            path.pop_back();
        }
    }
};

// code_end
