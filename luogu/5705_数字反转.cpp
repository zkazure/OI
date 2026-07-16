#include <iostream>
using namespace std;

int main() {
  char a[4];
  scanf("%c%c%c.%c", &a[0], &a[1], &a[2], &a[3]);

  printf("%c.%c%c%c", a[3], a[2], a[1], a[0]);

  return 0;
}
