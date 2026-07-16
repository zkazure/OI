// two even add to one even
// 2 1 1
// 4 2 2
// even and bigger than 2

#include <iostream>

int main() {
  int n;
  std::cin >> n;

  if(n%2) {
    std::cout << "NO\n";
  } else if (n>2 ) {
    std::cout << "YES\n";
  } else {
    std::cout << "NO\n";
  }

  return 0;
}
