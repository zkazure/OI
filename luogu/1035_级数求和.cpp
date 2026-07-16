#include <iostream>
using namespace std;

int main() {
  int k;
  cin >> k;
  double s = 0;
  for (int i=1; ;i++) {
    s += 1./i;
    if (s>k) {
      cout << i;
      return 0;
    }
  }

  return 0;
}
