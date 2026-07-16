// array a with n integer
// non-decreasing

#include <iostream>

int main()
{
  int n, m;
  std::cin >> n >> m;
  int a[n];
  for (int i=0; i<n; ++i)
  {
    std::cin >> a[i];
  }

  int b=0;
  int start=0;
  int end=n-1;

  for (int j=0; j<m; j++)
  {
    std::cin >> b;
    for(start=0; b>a[start]; start++);
    if (b==a[start])
      {
        for (;start <end; start++)
          {
            a[start] = a[start+1];
          }
        end--;
      }
  }

  for (int i=0; i<=end; i++)
  {
    std::cout << a[i];
  }

  return 0;
}
