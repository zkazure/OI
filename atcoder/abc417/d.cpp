#include <iostream>

int main()
{
  int n;
  std::cin >> n;
  int a[n][3];
  for (int i=0; i<n; i++)
  {
    for (int j=0; j<3; j++)
    {
      std::cin >> a[i][j];
    }
  }

  int q=0;
  std::cin >> q;
  int x[q];
  for (int i=0; i<q; i++)
  {
    std::cin >> x[i];
    int& v = x[i];
    for (int j=0; j<n; j++)
    {
      if (v >= a[j][0])
      {
        v += a[j][1];
      } else if (v > a[j][2])
      {
        v -= a[j][2];
      } else
      {
        v=0;
      }
    }
  }

  for (int i=0; i<q; i++)
  {
    std::cout << x[i];
  }

  return 0;
}
