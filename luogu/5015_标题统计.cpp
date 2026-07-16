#include <iostream>
#include <string>
using namespace std;

int main() {
  // printf("%d\n", '0'); // 48
  // printf("%d\n", '9'); // 57
  // printf("%d\n", 'a'); // 97
  // printf("%d\n", 'A'); // 65
  // printf("%d\n", 'z'); // 122
  // printf("%d\n", 'Z'); // 90

  string s;
  getline(cin, s);

  char* p = &s[0];
  int count = 0;

  while (*p!='\0') {
    if (*p <= 57 && *p>=48) {
      count++;
    } else if (*p <=97 && *p >=65) {
      count++;
    } else if (*p <= 122 && *p >=90) {
      count++;
    }
    p++;
  }

  printf("%d", count);
  return 0;

}

