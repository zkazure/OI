// day in reality is different with index
#include <iostream>

using namespace std;

int main () {
  int n, m, k;
  cin >> n >> m >> k;
  // int t[m][k]={0};
  // int count[k] ={0};
  int t[1000][1000]={0};
  int count[1000] ={0};
  
  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      int tmp;
      cin >> tmp;
      t[j][tmp-1] = 1;
    }
  }

  for (int i=0; i<k; i++) {
    for (int j=0; j<m; j++) {
      if (t[j][i]) {
        count[i]++;
      }
    }
  }

  for (int i=0; i<k; i++) {
    printf("%d ", count[i]);
  }

  return 0;
}
