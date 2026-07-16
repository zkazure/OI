#include <iostream>

int main()
{
  int a[3];
  int count = 0;
  bool check = false;

  for (int i=0; i<3; i++)
  {
    std::cin >> a[i];

  }

  for (int i=0; i<3; i++) {
    if (a[i]==5 ) {
      count ++;
    }
  }
  if (count == 2) {
    check = true;
  } else {
    std::cout << "NO" << std::endl;
    return 0;
  }


  count = 0;
  for (int i=0; i<3; i++) {
    if (a[i]==7 ) {
      count ++;
    }
  }
  if (count == 1)
    check = true;

  if (check) {
    std::cout << "YES" << std::endl;
  } else {
    std::cout << "NO" << std::endl;
  }

  return 0;
}
