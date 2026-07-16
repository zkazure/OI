#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  string s[n];
  for (int i=0; i<n; i++)
    cin >> s[i];

  // int point[100] = {0};
  int point[100] = {0};  
  for (int i=0; i<m; ++i) {
    int c_one = 0;
    for (int j=0; j<n; ++j) {
      if (s[j][i]-48)
        c_one++;
    }

    if (c_one > n/2) {
      for (int j=0; j<n; ++j)
        if (!(s[j][i]-48))
          point[j]++;
    } else {
      for (int j=0; j<n; ++j) 
        if ((s[j][i]-48))
          point[j]++;
    }
    
  }

  int m_point = 0;
  // sort(point, point+n);
  // m_point = point[m-1];
  for (int i=0; i<n; i++)
    m_point = max(m_point, point[i]);

  for (int i=0; i<n; i++) {
    if (point[i] == m_point)
      printf("%d ", i+1);
  }

  return 0;
  
}
