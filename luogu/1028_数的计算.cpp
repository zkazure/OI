// ===== crazy solution =====
// denote that f(n) is the amount of arraies started with n
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  int f[n+1];
  
  cin >> n;
  for (int i=1; i<=n; i++) {
    for (int j=1; j<=i/2; j++) {
      f[i] += f[j];
    }
    f[i] ++;
  }

  cout << f[n];

  return 0;
}



// ==== my solution =====
// to much TLE
#include <bits/stdc++.h>
using namespace std;

int count_array(int n) {
  int tmp_count=0;
  if (n) {
    tmp_count++;
    n /= 2;
    while (n) {
      tmp_count += count_array(n);
      n--;
    }
  }

  return tmp_count;
}

int main() {
  int n;
  cin >> n;

  int count = 0;
  count += count_array(n);

  cout << count;

  return 0;
  
}
