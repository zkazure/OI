#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 1e5 + 5;
int cola[MAXN];

int find_shops(int coins, int n) {
  int l = 1, r = n;
  // if (coins < cola[1])
  //   return 0;
  while (l <= r) {
    int mid = l + (r - l) / 2;
    if (coins >= cola[mid])
      l = mid + 1;
    else
      r = mid - 1;
  }

  return l - 1;
}

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> cola[i];
  }
  sort(cola + 1, cola + 1 + n);

  int m;
  cin >> m;
  for (int i = 1; i <= m; ++i) {
    int x;
    cin >> x;
    int ans = find_shops(x, n);
    cout << ans << "\n";
  }
}
