#include <functional>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

int T, S, D;
int a, b, ti;
int src = 0, dst = 1001;
const int MAXAB = 1005;
vector<pair<int, int>> graph[MAXAB];
int dist[MAXAB];

void dijkstra() {
    for (int i = 0; i < MAXAB; ++i) dist[i] = -1;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[src] = 0;
    pq.push({src, 0});

    while (!pq.empty()) {
        pair<int, int> prev = pq.top();
        pq.pop();

        if (prev.second != dist[prev.first]) continue;
        if (dst == prev.first) break;

        for (const pair<int, int> &e : graph[prev.first]) {
            int newDist = dist[prev.first] + e.second;

            if (dist[e.first] < 0 || newDist < dist[e.first]) {
                dist[e.first] = newDist;
                pq.push({e.first, newDist});
            }
        }
    }

    cout << dist[dst] << endl;
}

int main() {
    while (cin >> T >> S >> D) {
        for (int i = 0; i < MAXAB; ++i) {
            graph[i].clear();
        }
        for (int i = 0; i < T; ++i) {
            cin >> a >> b >> ti;
            graph[a].push_back({b, ti});
            graph[b].push_back({a, ti});
        }
        for (int i = 0; i < S; ++i) {
            cin >> a;
            graph[src].push_back({a, 0});
        }
        for (int i = 0; i < D; ++i) {
            cin >> b;
            graph[b].push_back({dst, 0});
        }

        dijkstra();
    }

}
