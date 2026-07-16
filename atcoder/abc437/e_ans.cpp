#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 3e5 + 5;
map<int, int> ch[MAXN];
int node[MAXN];
vector<int> ids[MAXN];
int n, tot;

void dfs(int v) {
  if (v) {
    sort(ids[v].begin(), ids[v].end());
    for (auto x : ids[v])
      cout << x;
  }
  for (auto [key, val] : ch[v]) {
    dfs(val);
  }
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int x, y;
    cin >> x >> y;
    int N = node[x];
    if (ch[N].count(y)) {
      node[i] = ch[N][y];
    } else {
      ++tot;
      ch[N][y] = tot;
      node[i] = tot;
    }
    ids[node[i]].push_back(i);
  }
  dfs(0);
  return 0;
}
