#include <bits/stdc++.h>
using namespace std;

// code_start

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    vector<int> ans;
    int top = 0;
    int right = matrix[0].size() - 1;
    int left = 0;
    int bottom = matrix.size() - 1;

    while (top <= bottom && left <= right) {
      for (int i = left; i <= right; i++) {
        ans.push_back(matrix[top][i]);
      }
      top += 1;
      for (int i = top; i <= bottom; i++) {
        ans.push_back(matrix[i][right]);
      }
      right -= 1;
      if (top <= bottom) {
        for (int i = right; i >= left; --i) {
          ans.push_back(matrix[bottom][i]);
        }
        bottom -= 1;
      }
      if (left <= right) {
        for (int i = bottom; i >= top; --i) {
          ans.push_back(matrix[i][left]);
        }
        left += 1;
      }
    }

    return ans;
  }
};

// code_end
