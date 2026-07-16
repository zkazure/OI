#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 3e5 + 5;
int nodes[MAXN];
vector<int> ids[MAXN];
map<int, int> chs[MAXN];
int cnt;

void dfs(int v) {
  if (v) {
    sort(ids[v].begin(), ids[v].end());
    for (auto x : ids[v])
      cout << x << " ";
  }
  for (auto [key, val] : chs[v]) {
    dfs(val);
  }
}

int main() {
  int N;
  cin >> N;
  for (int i = 1; i <= N; ++i) {
    int x, y;
    cin >> x >> y;
    int par = nodes[x];
    if (chs[par].count(y)) {
      nodes[i] = chs[par][y];
    } else {
      ++cnt;
      chs[par][y] = cnt;
      nodes[i] = cnt;
    }
    ids[nodes[i]].push_back(i);
  }
  dfs(0);

  return 0;
}
