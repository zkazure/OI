#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  string s, t;
  cin >> n >> m;
  cin >> s >> t;

  int l, r;
  for (int i=0; i<m; i++) {
    cin >> l >> r;

    string tmp = s;

    if( r==n ) {
      s = s.substr(0, l-1) + t.substr(l-1);
      t = t.substr(0, l-1) + tmp.substr(l-1);
    } else {
      s = s.substr(0, l-1) + t.substr(l-1, r-1) + s.substr(r);
      t = t.substr(0, l-1) + tmp.substr(l-1, r-1) + t.substr(r);      
    }

  }

  cout << s;

  return 0;
}
