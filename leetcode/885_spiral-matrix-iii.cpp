#include <bits/stdc++.h>
using namespace std;

// code_start

class Solution {
public:
  vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart,
                                      int cStart) {
    vector<vector<int>> ans(rows, vector<int>(cols));
    ans.clear();

    // find end point
    int rEnd, cEnd;
    if (rStart >= rows / 2)
      rEnd = -1;
    else
      rEnd = rows;
    if (cStart >= cols / 2)
      cEnd = -1;
    else
      cEnd = cols;

    // printf("%d %d", rEnd, cEnd);

    ans.push_back({rStart, cStart});
    int ridx = rStart, cidx = cStart;
    int east = 0, south = 0, west = 0, north = 0;
    while (true) {
      east = west + 1;
      if (ridx == rEnd && cidx <= cEnd && cidx + east >= cEnd) {
        break;
      }
      if (ridx >= 0 && ridx < rows) {
        for (int i = 1; i <= east && cidx + i < cols; i++) {
          if (cidx + i >= 0 && cidx + i < cols) {
            ans.push_back({ridx, cidx + i});
          }
        }
      }
      cidx += east;

      south = north + 1;
      if (cidx == cEnd && ridx <= rEnd && ridx + south >= rEnd) {
        break;
      }
      if (cidx >= 0 && cidx < cols) {
        for (int i = 1; i <= south; ++i) {
          if (ridx + i >= 0 && ridx + i < rows) {
            ans.push_back({ridx + i, cidx});
          }
        }
      }
      ridx += south;

      west = east + 1;
      if (ridx == rEnd && cidx >= cEnd && cidx - west <= cEnd) {
        // printf("%d %d", ridx, cidx);
        break;
      }
      if (ridx >= 0 && ridx < rows) {
        for (int i = 1; i <= west; ++i) {
          if (cidx - i >= 0 && cidx - i < cols) {
            ans.push_back({ridx, cidx - i});
          }
        }
      }
      cidx -= west;

      north = south + 1;
      if (cidx == cEnd && ridx >= rEnd && ridx - north <= rEnd) {
        // printf("%d %d", ridx, cidx);
        break;
      }
      if (cidx >= 0 && cidx < cols) {
        for (int i = 1; i <= north; ++i) {
          if (ridx - i >= 0 && ridx - i < rows) {
            ans.push_back({ridx - i, cidx});
          }
        }
      }
      ridx -= north;
    }

    return ans;
  }
};

// code_end

int main() {
  Solution s;
  s.spiralMatrixIII(5, 4, 0, 2);
}
