#include <bits/stdc++.h>
using namespace std;

int main() {
  // unsigned int a = -1;
  // cout << a;
  int n, q;
  cin >> n >> q;

  int a[n], b[n];
  for (int i=0; i<n; i++) 
    cin >> a[i];
  for (int i=0; i<n; i++) 
    cin >> b[i];

  long long ans = 0;
  for (int i=0; i<n; ++i)
    ans += min(a[i], b[i]);

  char c;
  int x, v;
  for (int i=0; i<q; ++i) {
    cin >> c >> x >> v;
    x-=1;
    // if (c=='A')
    //   a[x] = v;
    // else b[x] = v;

    if (c=='A') {
      ans -= min(a[x], b[x]);
      a[x] = v;
      ans += min(a[x], b[x]);
    } else {
      ans -= min(a[x], b[x]);
      b[x] = v;
      ans += min(a[x], b[x]);
    }
  printf("%lld\n", ans);
  }

  // long long ans=0;
  // for (int i=0; i<q; ++i) {
  //   ans += min(a[i], b[i]);
  // }

  // printf("%lld", ans);

  return 0;
}
