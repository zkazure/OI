#include <bits/stdc++.h>
using namespace std;

int main() {
  long long a, b, n;
  cin >> a >> b >> n;

  long long sum = ((a+ ( a+ (b-a)*(n-1) )) * n) /2;

  printf("%lld", sum);

  return 0;
}
