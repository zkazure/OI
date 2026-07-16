#include <bits/stdc++.h>
using namespace std;

static int b[200001] = {0};
static int edges[200001][200001] = {0};

int find_black(int k, int& n) {
  for (int i=1; i<=n; ++i) {
    if (edges[k][i]) {
      if (b[i])
        return 1;
      if (find_black(i, n)) {
        return 1;
      }
    }
  }

  return 0;
}

int main() {
  int n, q;
  cin >> n >> q;

  int con, u, v;
  for (int i=0; i<q; ++i) {
    cin >> con;
    switch (con) {
    case 1: {
      cin >> u >> v;
      edges[u][v] = 1;
      edges[v][u] = 1;
      break;
    }
    case 2: {
      cin >> v;
      if (b[v])
        b[v] = 0;
      else b[v] = 1;
      break;
    }
    case 3: {
      cin >> v;
      if (find_black(v, n))
        printf("Yes\n");
      else printf("No\n");
    }
    }
  }
  return 0;
}
