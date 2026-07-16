#include <bits/stdc++.h>
using namespace std;

// code_start

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size(), cols = board[0].size();
        vector<int> visited(rows * cols, 0);
        int idx = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (dfs()) {
                    return true;
                }
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>> &board, int row, int col,
             string &word, int idx, vector<int> &visited) {

        return false;
    }
};

// code_end
