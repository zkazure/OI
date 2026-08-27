#include <functional>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;

// at least 888
// if loop, -1

const int MAXN = 10005;
const int MAXM = 20005;
const int LEAST_REWARD = 888;
int n, m;
int a, b;

int heads[MAXN];
vector<pair<int, int>> edges;
int outdegrees[MAXN];
int reward;

int main() {
    while (cin >> n >> m) {
        for (int i = 1; i <= n; ++i) {
            heads[i] = -1;
            outdegrees[i] = 0;
        }
        edges.clear();
        reward = LEAST_REWARD * n;

        for (int i = 0; i < m; ++i) {
            cin >> a >> b;

            edges.push_back({a, heads[b]});
            heads[b] = edges.size() -1;
            outdegrees[a] += 1;
        }

        queue<int> que;
        for (int i = 1; i <= n; ++i) {
            if (outdegrees[i] == 0) {
                que.push(i);
            }
        }


        // 需要记录相同入度的节点，从而计算奖金。
        // 但是我们是从最小的开始计算的，所以使用出度更加合适。
        int cnt_loop = 0, cnt_worker = 0;
        int visited_n = 0;
        while (!que.empty()) {
            cnt_worker = 0;
            queue<int> tmp_que;
            while (!que.empty()) {
                int worker = que.front();
                que.pop();
                cnt_worker += 1;
                visited_n += 1;

                int in_edge_id = heads[worker];
                while (in_edge_id != -1) {
                    pair<int, int> e = edges[in_edge_id];
                    outdegrees[e.first] -= 1;
                    if (outdegrees[e.first] == 0) {
                        tmp_que.push(e.first);
                    }

                    in_edge_id = e.second;
                }
            }

            while (!tmp_que.empty()) {
                que.push(tmp_que.front());
                tmp_que.pop();
            }

            reward += cnt_worker * cnt_loop;
            cnt_loop += 1;
        }

        if (visited_n == n) {
            cout << reward << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}
