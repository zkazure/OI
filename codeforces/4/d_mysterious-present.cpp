#include <iostream>
using namespace std;

int main() {
  int n, w, h;
  cin >> n >> w >> h;

  int e[n][2];
  int index[n];
  for (int i=0; i<n; i++) {
    cin >> e[i][0] >> e[i][1];
    index[i] ++;
  }

  int count = n;
  for (int i=0; i<count-1; i++) {
    for (int j=i+1; j<count; j++) {
      if(e[index[i]][0] > e[index[j]][0]
         && e[index[i]][1] > e[index[j]][1]) {
        int tmp = index[i];
        index[i] = index[j];
        index[j] = tmp;
      }
    }
  }
}
