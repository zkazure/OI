#include <iostream>
using namespace std;

void reverse(int& n) {
  int tmp=n;
  cin >> n;
  if (n)
    reverse(n);
  cout << tmp << " ";
}

int main() {
  int n;
  cin >> n;
  reverse(n);

  return 0;
}
