#include <iostream>
using namespace std;

int main() {
  float t;
  int n;
  scanf("%f %d", &t, &n);

  n*=2;
  printf("%.3f", t/n);
  printf("%d", n);

  return 0;
}

