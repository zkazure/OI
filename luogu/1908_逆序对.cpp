#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, a[500000];
  scanf("%d", &n);
  for (int i=0; i<n; i++)
    scanf("%d", a+i);

  int c = 0;
  for (int i=0; i<n-1; i++) {
    for (int j=i+1; j<n; j++) {
      if (a[i] > a[j])
        c++;
    }
  }

  printf("%d", c);
  return 0;
}
  
