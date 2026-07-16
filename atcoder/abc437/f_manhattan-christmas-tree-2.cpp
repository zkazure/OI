#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 3e5 + 5;

struct SGT {
  pair<int, int> tree[MAXN << 2];
  pair<int, int> merge(pair<int, int> a, pair<int, int> b) {
    return pair(min(a.first, b.first), max(a.second, b.second));
  }

  void build(int a[], int x, int l, int r) {
    if (l == r) {
      tree[x] = pair(a[l], a[l]);
      return;
    }
    int mid = (l + r) >> 1;
    build(a, x << 1, l, mid);
    build(a, x << 1 | 1, mid + 1, r);
    tree[x] = merge(tree[x << 1], tree[x << 1 | 1]);
  }

  void update(int x, int l, int r, int p, int d) {
    if (l == r) {
      tree[x] = pair(d, d);
      return;
    }
    int mid = (l + r) >> 1;
    if (p <= mid)
      update(x << 1, l, mid, p, d);
    else
      update(x << 1 | 1, mid + 1, r, p, d);
    tree[x] = merge(tree[x << 1], tree[x << 1 | 1]);
  }

  pair<int, int> query(int x, int l, int r, int L, int R) {
    if (l == L && r == R) {
      return tree[x];
    }
    int mid = (l + r) >> 1;
    if (R <= mid)
      return query(x << 1, l, mid, L, R);
    else if (L > mid)
      return query(x << 1 | 1, mid + 1, r, L, R);
    else
      return merge(query(x << 1, l, mid, L, mid),
                   query(x << 1 | 1, mid + 1, r, mid + 1, R));
  }
} sgta, sgtb;

long long calc(long long v, pair<int, int> p) {
  return max(abs(v - p.first), abs(v - p.second));
}

int main() {
  int n, q;
  cin >> n >> q;
  int a[MAXN], b[MAXN];
  for (int i = 1; i <= n; ++i) {
    int x, y;
    cin >> x >> y;
    a[i] = x + y;
    b[i] = x - y;
  }
  sgta.build(a, 1, 1, n);
  sgtb.build(b, 1, 1, n);

  for (int i = 1; i <= q; ++i) {
    int op;
    cin >> op;
    if (op == 1) {
      int p, x, y;
      cin >> p >> x >> y;
      sgta.update(1, 1, n, p, x + y);
      sgtb.update(1, 1, n, p, x - y);
    } else {
      int L, R, x, y;
      cin >> L >> R >> x >> y;
      pair<int, int> resa = sgta.query(1, 1, n, L, R);
      pair<int, int> resb = sgtb.query(1, 1, n, L, R);
      long long ans = max(calc(x + y, resa), calc(x - y, resb));
      cout << ans << "\n";
    }
  }
  return 0;
}
