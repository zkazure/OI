#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  t++;

  int m;
  cin >> m;

  int l[m], r[m];
  int index[m];
  for (int i=0; i<m; i++) {
    cin >> l[i] >> r[i];
    index[i] = i;
  }

  for (int i=0; i<m-1; i++) {
    for (int j=i+1; j<m; j++) {
      if (l[index[i]] > l[index[j]]) {
        int tmp = index[i];
        index[i] = index[j];
        index[j] = tmp;
      }
    }
  }

  int min = l[index[0]], max = r[index[0]];
  for (int i=1; i<m; i++) {
    if (max >= l[index[i]]) {
      if (r[index[i]] > max) {
        max = r[index[i]];
      }
    } else {
      t-= (max-min+1);
      max = r[index[i]];
      min = l[index[i]];
    }
  }

  t-= (max-min+1);
  printf("%d", t);

  return 0;
}
