#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int r=1, c=1;

  int i=1;
  int n_hat=1; // (i+1)i/2
  while (n_hat<=n) {
    i++;
    n_hat= (i+1)*i /2;
  }
  i--;
  n_hat = (i+1)*i /2;

  int distance = n- n_hat-1;
  if (distance == -1) {
    if (i%2) {

      c = i;
      r=1;
    } else {
      r = i;
      c = 1;
    }
  } else {
    if(i%2) {
      c=i+1-distance;
      r=1+distance;

    } else {
      c= 1+distance;
      r= i+1-distance;
    }
  }


  printf("%d/%d", r, c);

  return 0;
}
