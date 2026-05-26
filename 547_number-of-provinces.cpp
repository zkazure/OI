#include <bits/stdc++.h>
using namespace std;

// code_start

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans = 0;
        int n = isConnected.size();
        vector<bool> visited(n, false);
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                ans += 1;
                dfs(isConnected, visited, i);
            }
        }

        return ans;
    }
    void dfs(const vector<vector<int>> &isConnected,
             vector<bool> &visited, int x) {
        visited[x] = true;
        for (int i = 0; i < isConnected.size(); ++i) {
            if (isConnected[x][i] && !visited[i]) {
                dfs(isConnected, visited, i);
            }
        }
    }
};

// code_end

class Solution1 {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans = 0;
        int n = isConnected.size();
        unordered_set<int> s;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (isConnected[i][j]) {
                    ++ans;
                    isConnected[i][j] = 0;
                    dfs(isConnected, i);
                    dfs(isConnected, j);
                    s.clear();
                }
            }
        }
        return ans;
    }
    void dfs(vector<vector<int>> &graph, int x) {
        for (int i = 0; i < graph.size(); ++i) {
            if (graph[x][i]) {
                graph[x][i] = 0;
                dfs(graph, i);
            }
        }
    }
};
