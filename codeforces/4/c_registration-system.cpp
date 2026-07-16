// n name
// insert database
// rename
// response

#include <iostream>
using namespace std;

int main() {
  int n;
  std::cin >> n;

  string* s[n];
  int index[n]={0};

  cin >> *s[0] ;
  index[0] ++;
  cout << "OK\n";

  for(int i=1; i<n; i++) {
    cin >> *s[i];

    for (int j=0; j<i; j++) {
      if (s[i] == s[j]) {
        cout << s[i] << index[i] << "\n";
        index[i]++;
      } else {
        cout << "OK\n";
      }
    }
  }

  return 0;
}

