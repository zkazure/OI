#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 205;

int n, m;
int a, b, x;
int s, t;

struct Edge {
    int to;
    int val;

    Edge(int t, int v) : to(t), val(v) {}
};

struct Compare_edge {
    bool operator()(const Edge& a, const Edge &b) const {
        return a.val > b.val;
    }
};

vector<Edge> roads[MAXN];
int dist[MAXN];

void dijkstra() {
    for (int i = 0; i < n; ++i) {
        dist[i] = -1;
    }
    priority_queue<Edge, vector<Edge>, Compare_edge> pq;

    dist[s] = 0;
    pq.push(Edge(s, 0));

    while (!pq.empty()) {
        Edge prev = pq.top();
        pq.pop();

        // 淘汰旧的无效路
        if (prev.val != dist[prev.to]) continue;
        if (prev.to == t) break;

        for (const Edge &e : roads[prev.to]) {
            int newDist = dist[prev.to] + e.val;
            // 只有距离更新的时候，才推入优先队列，避免重复添加导致死循环。
            if (dist[e.to] < 0 || newDist < dist[e.to]) {
                dist[e.to] = newDist;
                pq.push(Edge(e.to, dist[e.to]));
            }
        }
    }
    cout << dist[t] << endl;
}

int main() {
    while (cin >> n >> m) {
        for (int i = 0; i < MAXN; ++i) {
            roads[i].clear();
        }

        for (int i = 0; i < m; ++i) {
            cin >> a >> b >> x;
            roads[a].push_back(Edge(b, x));
            roads[b].push_back(Edge(a, x));
        }

        cin >> s >> t;
        dijkstra();
    }
}

/** 邻接表
struct Edge {
    int to;
    int val;

    Edge(int t, int v) : to(t), val(v) {}
};

vector<Edge> roads[MAXN];
int dist[MAXN];
bool found[MAXN];

void dijkstra() {
    for (int i = 0; i < n; ++i) {
        dist[i] = -1;
        found[i] = false;
    }

    dist[s] = 0;
    found[s] = true;
    int prev = s;

    for (int i = 0; i < n; ++i) {
        for (const Edge &e : roads[prev]) {
            if (found[e.to]) continue;

            if (dist[e.to] < 0)
                dist[e.to] = dist[prev] + e.val;
            else
                dist[e.to] = min(dist[prev] + e.val, dist[e.to]);
        }

        int ppre = prev;
        for (int j = 0; j < n; ++j) {
            if (dist[j] < 0 || found[j]) continue;

            if (prev == ppre || dist[j] < dist[prev])
                prev = j;
        }
        found[prev] = true;
        if (prev == t) {
            cout << dist[t] << endl;
            return ;
        }
    }
    cout << dist[t] << endl;
}

int main() {
    while (cin >> n >> m) {
        for (int i = 0; i < MAXN; ++i) {
            roads[i].clear();
        }

        for (int i = 0; i < m; ++i) {
            cin >> a >> b >> x;
            roads[a].push_back(Edge(b, x));
            roads[b].push_back(Edge(a, x));
        }

        cin >> s >> t;
        dijkstra();
    }
}
*/


/** 邻接矩阵

int roads[MAXN][MAXN];
int path[MAXN];
bool found[MAXN];

void dijkstra() {
    for (int i = 0; i < n; ++i) {
        path[i] = -1;
        found[i] = false;
    }

    path[s] = 0;
    found[s] = true;
    int prev = s;

    for (int i = 0; i < n; ++i) {
        // 每次找一个最短路，一共 n 次
        // 下一个最短路，要求一定直连，而和之前最短道路直连的路径已经计算过了
        // 因此需要遍历上一个最短路终点的所有相连道路
        for (int j = 0; j < n; ++j) {
            if (roads[prev][j] < 0 || prev == j || found[j]) continue;

            if (path[j] < 0) {
                path[j] = path[prev] + roads[prev][j];
            } else {
                path[j] = min(path[prev] + roads[prev][j],
                              path[j]);
            }
        }

        // 在已发现，但是还没有确定是最短路的路径中，更新最短路
        int ppre = prev;
        for (int j = 0; j < n; ++j) {
            if (found[j] || path[j] < 0) continue;

            if (prev == ppre || path[j] < path[prev])
                prev = j;
        }
        found[prev] = true;
    }

    cout << path[t] << endl;
}

int main() {
    while (cin >> n >> m) {
        for (int i = 0; i < MAXN; ++i) {
            for (int j = 0; j < MAXN; ++j) {
                roads[i][j] = -1;
            }
            roads[i][i] = 0;
        }

        for (int i = 0; i < m; ++i) {
            cin >> a >> b >> x;
            if (roads[a][b] < 0)
                roads[a][b] = x;
            else
                roads[a][b] = min(roads[a][b], x);

            roads[b][a] = roads[a][b];
        }

        cin >> s >> t;
        dijkstra();
    }
}

*/
