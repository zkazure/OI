#include <iostream>
using namespace std;

int main() {
  int n, x;
  cin >> n >> x;
  int d[10]={0};

  int r = 0;
  for (int i=1; i<=n; i++) {
    int tmp = i;
    while(tmp) {
      d[tmp%10]++;
      tmp/=10;
    }
  }

  cout << d[x];
  return 0;
}
