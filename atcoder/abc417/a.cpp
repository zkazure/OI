// substring

#include <iostream>
using namespace std;

int main()
{
  int n, a, b;
  string s;
  cin >> n >> a >> b >> s;
  // int n=7, a=1, b=3;
  // string s="atcoder";


  s[n-b] = '\0';
  s = &s[a];

  cout << s;

  return 0;
}
