#include <vector>
using namespace std;

// code_start

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if (r * c != mat.size() * mat[0].size()) {
            return mat;
        }

        vector<vector<int>> new_mat(r, vector<int>(c, 0));
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                int total = j + i * c;
                int x = total / mat[0].size();
                int y = total - x * mat[0].size();

                new_mat[i][j] = mat[x][y];
            }
        }

        return new_mat;
    }
};

// code_end
