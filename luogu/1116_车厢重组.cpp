// ======= awesome solution =======
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, sum;
  int a[10000];
  scanf("%d", &n);
  for (int i=0; i<n; i++)
    scanf("%d", a+i);

  for (int i=0; i<n; ++i)
    for (int j=0; j<i; ++j) {
      if (a[j] > a[i])
        ++sum;
    }
}



// ===== my solution =====
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  int a[10000];

  scanf("%d", &n);
  for (int i=0; i<n; i++) {
    scanf("%d", a+i);
  }

  int count = 0;
  for (int i=0; i<n-1; i++) {
    for (int j=0; j<n-i-1; j++) {
      if (a[j] > a[j+1]) {
        swap(a[j], a[j+1]);
        count++;
      }
    }
  }

  printf("%d", count);
}
