#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, y;
  scanf("%d %d", &x, &y);
  int z = x+y;

  if (z<=12) {
    printf("%d", z);
  } else printf("%d", z-12);

  return 0;
}
