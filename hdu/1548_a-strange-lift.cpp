#include <queue>
#include <iostream>
using namespace std;

// lift [1, N] A->B
int N, A, B;

const int MAXN = 200;
int ks[MAXN + 5];
int dis[MAXN + 5];

void bfs() {
    dis[A] = 0;

    queue<int> floors;
    floors.push(A);


    while (!floors.empty()) {
        int cur = floors.front(); floors.pop();

        if (cur == B) {
            cout << dis[cur] << endl;
            return;
        }

        int down = cur-ks[cur];
        int up = cur+ks[cur];

        if (up <= N && dis[up] == -1) {
            floors.push(up);
            dis[up] = dis[cur] + 1;
        }
        if (down >= 1 && dis[down] == -1) {
            floors.push(down);
            dis[down] = dis[cur] + 1;
        }
    }

    cout << -1 << endl;
    return;
}

int main() {
    while (cin >> N && N != 0) {
        cin >> A >> B;

        for (int i = 1; i <= N; i += 1) {
            cin >> ks[i];
            dis[i] = -1;
        }

        bfs();
    }

}
