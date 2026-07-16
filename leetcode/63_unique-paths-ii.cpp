#include <bits/stdc++.h>
using namespace std;

// code_start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[0][0]==1)
            return 0;

        int dp[105][105] = {0};
        int m=obstacleGrid.size(), n=obstacleGrid[0].size();
        for (int i=0; i<n && obstacleGrid[0][i]==0; i++)
            dp[0][i] = 1;
        for (int i=0; i<m && obstacleGrid[i][0]==0; i++)
            dp[i][0] = 1;

        for (int i=1; i<m; ++i) {
            for (int j=1; j<n; ++j) {
                if (obstacleGrid[i][j]==0)
                    dp[i][j]= dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[m-1][n-1];
    }
};

// code_end

class wrongSolution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size(), n=obstacleGrid[0].size();
        
        int dp[105][105];
        for (int i=0; i<m; ++i)
            dp[i][0] = 1;
        for (int i=0; i<n; ++i)
            dp[0][i] = 1;

        int om, on;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (obstacleGrid[i][j]==1) {
                    om = i, on = j;
                    dp[om][on] = 0;
                    if (om==0) {
                        for (int k=on+1; k<n; ++k)
                            dp[0][k] = 0;
                    }
                    if (on==0) {
                        for (int k=om+1; k<m; ++k)
                            dp[k][0] = 0;
                    }
                        
                    continue;
                }
            }
        }


        for (int i=1; i<m; ++i) {
            for (int j=1; j<n; ++j) {
                if (i==om && j==on) {
                    dp[i][j] = 0;
                    continue;
                }
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[m-1][n-1];
    }
};
