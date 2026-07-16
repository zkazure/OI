#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  int count = 0;
  cin >> n;

  int tmp;
  int q[n];
  for (int i=0; i<n; i++) {
    cin >> tmp;
    if(tmp == 1) {
      cin >> q[count];
      count++;
    } else {
      sort(q, q+count, greater<int>());
      count --;
      printf("%d\n", q[count]);
    }
  }
  
  return 0;
}
