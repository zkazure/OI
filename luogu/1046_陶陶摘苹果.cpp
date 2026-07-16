#include <iostream>
using namespace std;

int main() {
  int h[10];
  for (int i=0; i<10; i++) {
    cin >> h[i];
  }
  int m;
  cin >> m;
  m += 30;
  int count = 0;

  for (int i=0; i<10; i++) {
    if (m>=h[i])
      count ++;
  }

  printf("%d", count);

  return 0;
}
