#include <bits/stdc++.h>
#include <vector>
using namespace std;

// code_start

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int dir = 0;
        int i=0, j=0;
        int up=0, right=n-1, down=n-1, left=0;
        for (int k=1; k<=n*n; k++) {
            switch (dir) {
            case 0: {
                ans[i][j++] = k;
                if (j>right) {
                    dir = 1;
                    j = right;
                    i++;
                    up++;
                }
                break;
            }
            case 1: {
                ans[i++][j] = k;
                if (i>down) {
                    dir = 2;
                    i = down;
                    j--;
                    right--;
                }
                break;
            }
            case 2: {
                ans[i][j--] = k;
                if (j<left) {
                    dir = 3;
                    j = left;
                    i--;
                    down--;
                }
                break;
            }
            case 3: {
                ans[i--][j] = k;
                if (i<up) {
                    dir = 0;
                    i = up;
                    j++;
                    left++;
                }
                break;
            }
            }
        }

        return ans;
    }
};

// code_end

