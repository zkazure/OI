#include <cmath>
#include <iostream>
using namespace std;

// not return, enter D at T.
const int MAXMN = 7;
bool sinked[MAXMN][MAXMN];
char maze[MAXMN][MAXMN];
int dirs[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
bool survived = false;

int N, M, T;
int dx, dy;

void dfs(int row, int col, int sec) {
    // enter maze[row][col] at sec second.
    if (survived || sec > T) return;

    if (sec == T && maze[row][col] == 'D') {
        survived = true;
        return;
    }

    int dis = abs(dx - row) + abs(dy - col);
    int remain = T - sec;
    if (remain < dis || (remain-dis)%2 != 0)
        return ;

    sinked[row][col] = true;
    for (int i = 0; i < 4; i += 1) {
        int nrow = row + dirs[i][0];
        int ncol = col + dirs[i][1];

        if (nrow >= N || nrow < 0 ||
            ncol >= M || ncol < 0)
            continue;
        if (maze[nrow][ncol] != '.' && maze[nrow][ncol] != 'D')
            continue;
        if (sinked[nrow][ncol])
            continue;

        dfs(nrow, ncol, sec + 1);
    }

    sinked[row][col] = false;
}

int main() {
    while (cin >> N >> M >> T && N != 0) {
        survived = false;

        for (int i = 0; i < N; i += 1) {
            for (int j = 0; j < M; j += 1) {
                cin >> maze[i][j];
                if (maze[i][j] == 'D')
                    dx = i, dy = j;
            }
        }

        for (int i = 0; i < N; i += 1) {
            for (int j = 0; j < M; j += 1) {
                if (maze[i][j] == 'S') {
                    dfs(i, j, 0);
                }
            }
        }

        if (survived)
            cout << "YES";
        else
            cout << "NO";

        cout << "\n";
    }

    return 0;
}
