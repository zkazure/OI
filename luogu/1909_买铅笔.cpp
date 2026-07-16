#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  unsigned int sum=-1;
  int count = 0;
  int num = 0;
  int one, prize;
  for (int i=0; i<3; i++) {
    cin >> one >> prize;
    num = 0;
    count = 0;
    while (num < n) {
      num += one;
      count++;
    }
    if (sum > prize*count) {
      sum = prize*count;
    }
  }

  cout << sum;
  return 0;
}
