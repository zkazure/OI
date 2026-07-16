#include <bits/stdc++.h>
using namespace std;

// code_start

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;

        int cnt = 0;
        int rows = grid.size(), cols = grid[0].size();

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == '1') {
                    cnt += 1;
                    bfs(grid, i, j, rows, cols);
                }
            }
        }
        return cnt;
    }

private:
    void bfs(vector<vector<char>> &grid, int r, int c, int rows, int cols) {
        if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == '0')
            return;
        grid[r][c] = '0';

        queue<pair<int, int>> que;
        que.push({r, c});
        vector<pair<int, int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        while (!que.empty()) {
            auto cur = que.front(); que.pop();
            for (auto dir : dirs) {
                int rr = cur.first + dir.first;
                int cc = cur.second + dir.second;
                if (rr < 0 || rr >= rows
                    || cc < 0 || cc >= cols
                    || grid[rr][cc] == '0')
                    continue;
                grid[rr][cc] = '0';
                que.push({rr, cc});
            }
        }
    }
    void dfs(vector<vector<char>> &grid, int r, int c, int rows, int cols) {
        if (r >= rows || c >= cols ||  r < 0 || c < 0 || grid[r][c] == '0')
            return;

        grid[r][c] = '0';
        dfs(grid, r - 1, c, rows, cols);
        dfs(grid, r, c - 1, rows, cols);
        dfs(grid, r + 1, c, rows, cols);
        dfs(grid, r, c + 1, rows, cols);
    }
};

// code_end
