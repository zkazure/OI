#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W, N;
  cin >> H >> W >> N;
  set<int> rows[H];
  for (auto row : rows) {
    row.clear();
  }
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      int tmp;
      cin >> tmp;
      rows[i].insert(tmp);
    }
  }

  int call[N];
  for (int i = 0; i < N; ++i) {
    cin >> call[i];
  }
  int ans = 0;
  for (int i = 0; i < H; ++i) {
    int tmp = 0;
    for (int j = 0; j < N; ++j) {
      if (rows[i].find(call[j]) != rows[i].end())
        tmp++;
    }
    ans = max(ans, tmp);
  }
  cout << ans;

  return 0;
}
