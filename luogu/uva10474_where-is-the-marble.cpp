#include <algorithm>
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int main() {
  int n, q, x;
  const int maxn = 10;
  int a[maxn];

  scanf("%d %d", &n, &q);

  int case_count = 1;
  while (n && q) {
    for (int i=0; i<n; i++) {
      scanf("%d", a+i);
    }
    sort(a, a+n);

    printf("CASE# %d:\n", case_count);
    
    for (int i=0; i<q; i++) {
      scanf("%d", &x);
      int tmp = lower_bound(a, a+n, x) -a;
      
      if (a[tmp]==x) {
        printf("%d found at %d\n", x, tmp+1);
      } else {
        printf("%d not found\n", x);
      }
    }

    scanf("%d %d", &n, &q);
    case_count++;
  }

  return 0;

}
