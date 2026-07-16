#include <bits/stdc++.h>
using namespace std;

// code_start

class Solution {
private:
    bool dfs(const vector<vector<int>> &adj,
             vector<bool> &visited, vector<bool> &path,
             int course) {
        visited[course] = true, path[course] = true;

        for (const auto &next : adj[course]) {
            if (!visited[next]) {
                if (!dfs(adj, visited, path, next))
                    return false;
            } else if (path[next]) {
                return false;
            }
        }


        path[course] = false;
        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (const auto &pre : prerequisites) {
            int dst = pre[0], src = pre[1];
            adj[src].push_back(dst);
        }

        vector<bool> visited(numCourses, false), path(numCourses, false);
        for (int course = 0; course < numCourses; ++course) {
            if (!visited[course] && !dfs(adj, visited, path, course)) {
                return false;
            }
        }

        return true;
    }
};

// bfs
class Solution1 {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for (const auto &pre : prerequisites) {
            int dst = pre[0], src = pre[1];
            adj[src].push_back(dst);
            indegree[dst]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0)
                q.push(i);
        }

        int count = 0;
        while (!q.empty()) {
            int vertex = q.front();
            q.pop();
            count += 1;

            for (const auto &next : adj[vertex]) {
                indegree[next]--;
                if (indegree[next] == 0)
                    q.push(next);
            }
        }

        return count == numCourses;
    }
};

// code_end
