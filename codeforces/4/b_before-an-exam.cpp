 // days sum
// check sum whether in the range
// output how


#include <iostream>

int main() {
  int n, sum;
  std::cin >> n >> sum;

  int t1[n], t2[n];
  int min=0, max=0;
  int s[n];
  for (int i=0; i<n; i++) {
    std::cin >> t1[i] >> t2[i];
    s[i] = t1[i];
    min += t1[i];
    max += t2[i];
  }

  if (sum >= min && sum <= max) {
    std::cout << "YES\n";
  } else {
    std::cout << "NO\n";
    return 0;
  }

  int total = min;
  for (int i=0; i<n; i++) {
    while (total < sum) {
      if(s[i]<t2[i]) {
        s[i]++;
      } else {
        break;
      }
    }
    if (total == sum)
      break;
  }

  for(int i=0; i<n; i++)
    {
      std::cout <<s[i] << ' ';
    }

  std::cout << "\n";

  return 0;
}
