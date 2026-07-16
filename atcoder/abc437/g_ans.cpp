#include <atcoder/maxflow>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

constexpr int MAXN = 2000 + 5;
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

  mf_graph<int> g(3 * n + 2);
  int S = 3 * n, T = 3 * n + 1;
  for (int v = 0; v < n; ++v) {
    int cnt[3] = {0, 0, 0};
    int now = col[v];
    for (int i = 1; i <= G[v].size(); ++i) {
      ++cnt[now];
      (now += 1) %= 3;
    }
    for (int c = 0; c <= 2; ++c) {
      if (!bi[v]) {
        g.add_edge(S, id(v, c), cnt[c]);
      } else {
        g.add_edge(id(v, c), T, cnt[c]);
      }
    }
  }
  for (int v = 0; v < n; ++v) {
    if (bi[v])
      continue;
    for (auto x : G[v]) {
      for (int c1 = 0; c1 <= 2; ++c1) {
        for (int c2 = 0; c2 <= 2; ++c2) {
          if (c1 == c2)
            continue;
          g.add_edge(id(v, c1), id(x, c2), 1);
        }
      }
    }
  }
  int flow = g.flow(S, T);
  if (flow != n - 1) {
    puts("No");
    return;
  }
  puts("Yes");
  vector<tuple<int, int, int, int>> vec;
  for (auto e : g.edges()) {
    if (e.flow == 1 && e.from < 3 * n && e.to < 3 * n) {
      int u = e.from / 3, cu = e.from % 3;
      int v = e.to / 3, cv = e.to % 3;
      vec.push_back({u, cu, v, cv});
    }
  }
  while (!vec.empty()) {
    for (int i = 0; i < vec.size(); ++i) {
      auto [u, cu, v, cv] = vec[i];
      if (col[u] == cu && col[v] == cv) {
        if (u > v)
          swap(u, v);
        cout << edge_id[make_pair(u, v)];
        (col[u] += 1) %= 3;
        (col[v] += 1) %= 3;
        vec.erase(vec.begin() + i);
      }
    }
  }
  puts("");
}

int main() {
  int T;
  cin >> T;
  while (T--)
    Solve();
  return 0;
}
