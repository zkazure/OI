// 300 in
// save 100 end .2
// start month no 100
// monitor negative

#include <iostream>
using namespace std;

int main() {
  int b[12];
  for (int i=0; i<12; i++) {
    cin >> b[i];
  }

  int c=0, s=0;
  for (int i=0; i<12; i++) {
    c+=300;
    c-=b[i];
    if(c<0) {
      cout << (-i-1);
      return 0;
    }
    s += c/100*100;
    c = c%100;
  }
  s = s*1.2+c;
  printf("%d", s);

  return 0;
}
