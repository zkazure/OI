#include <bits/stdc++.h>
using namespace std;

int main() {
  int a[100]= {0};
  
  int count_same = 0;
  int n;
  scanf("%d", &n );

  int count_len = 0;
  for (int i=0; i<n; i++) {
    int tmp;
    scanf("%d", &tmp);

    int k = lower_bound(a, a+count_len, tmp)-a;
    if (a[k]==tmp) {
      count_same++;
    } else {
      a[count_len] = tmp;
      count_len++;
      sort(a, a+count_len);
    }
  }

  printf("%d\n", n-count_same);
  
  sort(a, a+count_len);
  for (int i=0; i<count_len; i++)
    printf("%d ",a[i]);

  return 0;
}
