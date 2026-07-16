// integer >= 1

#include <iostream>

int main()
{
  int n = 0;
  std::cin >> n;

  int a[n];
  for (int i=0; i<n; i++)
  {
    std::cin >> a[i];
  }

  int count =0;
  int start=0, end=0;
  for (int c=2; ;c++)
  {
    if (c==n)
      break;
    for (start=0;;start++)
    {
      end = start+c;
      if (end>=n)
      {
        break;
      }
      if (a[start]+a[end]==c)
      {
        count++;
      }
    }
  }

  std::cout << count;
  return 0;
}
