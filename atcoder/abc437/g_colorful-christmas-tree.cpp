#include <atcoder/maxflow>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

constexpr int MAXN = 2e3 + 5;
int n;
char str[MAXN];
int col[MAXN];
vector<int> G[MAXN];
bool bi[MAXN];
map<pair<int, int>, int> edge_id;

void dfs(int v, int fa = -1) {
  for (auto x : G[v]) {
    if (x == fa)
      continue;
    bi[x] = bi[v] ^ 1;
    dfs(x, v);
  }
}

int id(int v, int c) { return 3 * v + c; }

inline void Solve() {
  cin >> n >> str;
  for (int i = 0; i <= n - 1; ++i) {
    if (str[i] == 'R')
      col[i] = 0;
    else if (str[i] == 'G')
      col[i] = 1;
    else
      col[i] = 2;
    G[i].clear();
  }

  edge_id.clear();

  for (int i = 1; i <= n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    if (u > v)
      swap(u, v);
    edge_id[make_pair(u, v)] = i;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  bi[0] = 0;
  dfs(0);
}
