#include <bits/stdc++.h>
using namespace std;

int n, k;
int counter=0;
int x[25];

bool is_prime(int& n) {
  if (n==2 || n==3) {
    return true;
  }

  if (n%2==0) {
    return false;
  }

  for (int i=3; i<n; i+=2) {
    if(n%i==0)
      return false;
  }

  return true;
}

void select_number(int amount, int cur_index, int sum) {
  
  if (amount==k) {
    if (is_prime(sum))
      counter++;
    return;
  } else {
    for (int i=cur_index; i<n-k+amount+1; i++) {
      select_number(amount+1, i+1, sum+x[i]);
    }
    return;
  }
  
}

int main() {
  cin >> n >> k;
  for (int i=0; i<n; i++) {
    cin >> x[i];
  }

  select_number(0, 0, 0);

  cout << counter;
}
