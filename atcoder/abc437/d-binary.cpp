#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 3e5 + 5;
constexpr int mod = 998244353;

int N, M;
int A[MAXN], B[MAXN];
int pre[MAXN], suf[MAXN];

int main() {
  cin >> N >> M;
  for (int i = 1; i <= N; ++i) {
    cin >> A[i];
  }
  for (int i = 1; i <= M; ++i) {
    cin >> B[i];
  }
  sort(B + 1, B + M + 1);

  for (int i = 1; i <= M; ++i) {
    pre[i] = (pre[i - 1] + B[i]) % mod;
  }
  for (int i = M; i >= 1; --i) {
    suf[i] = (suf[i + 1] + B[i]) % mod;
  }

  int ans = 0;
  for (int i = 1; i <= N; ++i) {
    int k = upper_bound(B + 1, B + 1 + M, A[i]) - B - 1;
    (ans += 1ll * A[i] * (k - (M - k)) % mod) %= mod;
    (ans += mod - pre[k]) %= mod;
    (ans += suf[k + 1]) %= mod;
  }
  cout << ans << "\n";

  return 0;
}
