#include <iostream>
using namespace std;

int main() {
  char a[10];
  scanf("%c-%c%c%c-%c%c%c%c%c-%c", &a[0], &a[1], &a[2], &a[3], &a[4], &a[5], &a[6], &a[7], &a[8], &a[9]);

  int test = 0;
  for (int i=0; i<9; i++) {
    int tmp = a[i] - '0';
    test += tmp*(i+1);
  }

  test %= 11;
  if (test==10) {
    test = 'X'-'0';
  }
  if (test==a[9]-'0') {
    printf("Right\n");
  } else {
    a[9] = test+'0';
    printf("%c-%c%c%c-%c%c%c%c%c-%c", a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8], a[9]);    
  }

  return 0;
}
