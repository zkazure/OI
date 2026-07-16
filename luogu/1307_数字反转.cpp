// n
// reverse digit
#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int reverse = 0;

  while (n) {
    reverse = reverse*10 + n%10;
    n/=10;
  }

  printf("%d", reverse);
  return 0;
}

