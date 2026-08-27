#include <functional>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

const int MAXN = 505;
int N, M;
int a, b;

int heads[MAXN];
int indegree[MAXN];
vector<pair<int, int>> edges;

void star_add(int from, int to) {
    if (heads[from] == -1) {
        edges.push_back({to, -1});
    } else {
        edges.push_back({to, heads[from]});
    }

    indegree[to] += 1;
    heads[from] = edges.size() - 1;
}

int main() {
    while (cin >> N >> M) {
        for (int i = 1; i <= N; ++i) {
            heads[i] = -1;
            indegree[i] = 0;
        }
        edges.clear();

        for (int i = 0; i < M; ++i) {
            cin >> a >> b;

            star_add(a, b);
        }

        priority_queue<int, vector<int>, greater<int>> que;
        for (int i = 1; i <= N; ++i) {
            if (indegree[i] == 0) {
                que.push(i);
            }
        }
        while (!que.empty()) {
            int node = que.top();
            que.pop();
            cout << node << " ";

            int end = heads[node];
            while (end != -1) {
                pair<int, int> e = edges[end];

                indegree[e.first] -= 1;
                if (indegree[e.first] == 0) {
                    que.push(e.first);
                }

                end = e.second;
            }
        }
    }
}

/** 邻接表
#include <functional>
#include <queue>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

const int MAXN = 500;
vector<int> graph[MAXN + 5];
int in[MAXN + 5] = {0};

int main() {
    int N, M;
    while (cin >> N >> M) {
        for (int i = 0; i < MAXN + 5; ++i) {
            graph[i].clear();
            in[i] = 0;
        }

        for (int i = 0; i < M; ++i) {
            int a, b; cin >> a >> b;
            graph[a].push_back(b);
            in[b] += 1;
        }

        priority_queue<int, vector<int>, greater<int>> q;
        for (int i = 1; i <= N; ++i) {
            if (in[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int node = q.top();
            q.pop();
            cout << node << " ";

            for (const int to : graph[node]) {
                in[to] -= 1;

                if (in[to] == 0) {
                    q.push(to);
                }
            }
        }
    }
}
*/
