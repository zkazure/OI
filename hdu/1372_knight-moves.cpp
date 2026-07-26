#include <iostream>
#include <queue>
#include <string>
using namespace std;

using Pos = pair<int, int>;

// [1-8], [a-h]
const int MAXN = 8;
Pos dirs[8] = {{2, 1},   {2, -1}, {1, -2}, {-1, -2},
               {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}};
int diss[MAXN][MAXN];
string src, dst;

Pos s2pos(string input) { return {input[0] - 'a', input[1] - '1'}; }

void bfs() {
    Pos start = s2pos(src);
    Pos end = s2pos(dst);
    diss[start.first][start.second] = 0;

    queue<Pos> q;
    q.push(start);
    while (!q.empty()) {
        Pos curr = q.front();
        q.pop();

        if (curr == end) {
            cout << "To get from " << src << " to " << dst << " takes "
                 << diss[curr.first][curr.second] << " knight moves." << endl;
            return;
        }

        for (int i = 0; i < MAXN; ++i) {
            int nx = curr.first + dirs[i].first;
            int ny = curr.second + dirs[i].second;

            if (nx < 0 || nx >= MAXN || ny < 0 || ny >= MAXN || diss[nx][ny] != -1) {
                continue;
            }

            q.push({nx, ny});
            diss[nx][ny] = diss[curr.first][curr.second] + 1;
        }
    }
}

int main() {
    while (cin >> src >> dst) {
        for (int i = 0; i < MAXN; i += 1) {
            for (int j = 0; j < MAXN; j += 1) {
                diss[i][j] = -1;
            }
        }

        bfs();
    }
}
