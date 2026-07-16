// 8 learn
// 8 h
#include <iostream>
using namespace std;

int main() {
  int d,h;
  int md=0, mh=0;
  for (int i=1; i<=7; i++) {
    int a, b;
    cin >> a >> b;
    h = a+b-8;
    if(h>0 && h>mh) {
      md = i;
      mh = h;
    }
  }

  cout << md;

  return 0;
}
