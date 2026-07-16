#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 2e5 + 5;
int n, q;

struct SGT {
#define lc ((x) << 1)
#define rc ((x) << 1 | 1)
  pair<int, int> tr[MAXN << 2];
  pair<int, int> merge(pair<int, int> x, pair<int, int> y) {
    return make_pair(min(x.first, y.first), max(x.second, y.second));
  }

  void build(int a[], int x, int l, int r) {
    if (l == r) {
      tr[x] = make_pair(a[l], a[l]);
      return;
    }
    int mid = (l + r) >> 1;
    build(a, lc, l, mid);
    build(a, rc, mid + 1, r);
    tr[x] = merge(tr[lc], tr[rc]);
  }

  void update(int x, int l, int r, int p, int d) {
    if (l == r) {
      tr[x] = make_pair(d, d);
      return;
    }
    int mid = (l + r) >> 1;
    if (p <= mid)
      update(lc, l, mid, p, d);
    else
      update(rc, mid + 1, r, p, d);
    tr[x] = merge(tr[lc], tr[rc]);
  }
  pair<int, int> query(int x, int l, int r, int L, int R) {
    if (l == L && r == R)
      return tr[x];
    int mid = (l + r) >> 1;
    if (R <= mid)
      return query(lc, l, mid, L, R);
    else if (L > mid)
      return query(rc, mid + 1, r, L, R);
    else
      return merge(query(lc, l, mid, L, mid),
                   query(rc, mid + 1, r, mid + 1, R));
  }

} sgt_x, sgt_y;

long long calc(long long x, pair<long long, long long> res) {
  return max(abs(x - res.first), abs(x - res.second));
}

int x[MAXN], y[MAXN];

int main() {
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    int xx, yy;
    cin >> xx >> yy;
    x[i] = xx + yy;
    y[i] = xx - yy;
  }
  sgt_x.build(x, 1, 1, n);
  sgt_y.build(y, 1, 1, n);
  for (int i = 1; i <= q; ++i) {
    int op;
    cin >> op;
    if (op == 1) {
      int p, xx, yy;
      cin >> p >> xx >> yy;
      int x = xx + yy, y = xx - yy;
      sgt_x.update(1, 1, n, p, x);
      sgt_y.update(1, 1, n, p, y);
    } else {
      int L, R, xx, yy;
      cin >> L >> R >> xx >> yy;
      int x = xx + yy, y = xx - yy;
      auto res_x = sgt_x.query(1, 1, n, L, R);
      auto res_y = sgt_y.query(1, 1, n, L, R);
      long long ans = max(calc(x, res_x), calc(y, res_y));
      cout << ans << "\n";
    }
  }
  return 0;
}
