#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 3e5 + 5;
int T, N;
long long wp[MAXN];
long long delta;

void solve() {
  cin >> N;
  delta = 0;
  for (int i = 1; i <= N; ++i) {
    long long w, p;
    cin >> w >> p;
    wp[i] = w + p;
    delta += p;
  }
  sort(wp + 1, wp + 1 + N);
  for (int i = 1; i <= N; ++i) {
    delta -= wp[i];
    if (delta < 0) {
      cout << i - 1 << "\n";
      return;
    }
  }
}

int main() {
  cin >> T;
  for (int i = 1; i <= T; ++i) {
    solve();
  }

  return 0;
}
