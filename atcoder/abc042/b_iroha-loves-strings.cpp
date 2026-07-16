#include <iostream>

int main()
{
  int n, l;
  std::cin >> n >> l;
  std::string s[n];
  int index[n];

  for (int i=0; i<n; i++)
  {
    index[i] = i;
    std::cin >> s[i];
  }

  for (int i=0; i<n-1; i++)
  {
    for (int j=i+1; j<n; j++)
    {
      if (s[index[i]] > s[index[j]]) {
        int tmp = index[i];
        index[i] = index[j];
        index[j] = tmp;
      }
    }
  }

  for (int i=0; i<n; i++)
  {
    std::cout << s[index[i]];
  }

  std::cout << std::endl;

  return 0;
}

