#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;
int L[MAXN], R[MAXN];
bool removed[MAXN];

void insert(int u, int v, int p) {
    if (p == 0) {
        L[v] = L[u];
        L[u] = v;
        R[L[v]] = v;
        R[v] = u;
    } else {
        R[v] = R[u];
        R[u] = v;
        L[R[v]] = v;
        L[v] = u;
    }
}

void remove(int u) {
    if (removed[u]) return;
    R[L[u]] = R[u];
    L[R[u]] = L[u];
    removed[u] = true;
}

void print() {
    int curr = R[0];
    while (curr != 0) {
        cout << curr << " ";
        curr = R[curr];
    }
    cout << "\n";
}

int main() {
    int n, m;
    int k, p, r;
    cin >> n;
    R[0] = 1; R[1] = 0;
    L[0] = 1; L[1] = 0;
    for (int i = 2; i <= n; ++i) {
        cin >> k >> p;
        insert(k, i, p);
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> r;
        remove(r);
    }
    print();

    return 0;
}
