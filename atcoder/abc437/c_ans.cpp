#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 3e5 + 5;
int N, T;
long long wp[MAXN];
long long delta;

inline void Solve() {
  cin >> N;
  delta = 0;
  for (int i = 1; i <= N; ++i) {
    long long w, p;
    cin >> w >> p;
    wp[i] = w + p;
    delta += p;
  }
  sort(wp + 1, wp + N + 1);
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
    Solve();
  }

  return 0;
}
