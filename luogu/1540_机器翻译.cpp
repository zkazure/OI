#include <bits/stdc++.h>
using namespace std;

const int M = 1e3 + 5;
int m, n;
int que[M];
int head = 0, tail = -1, siz = 0;

bool find(int x) {
    for (int i = 0; i < siz; ++i) {
        int idx = (head + i) % M;
        if (que[idx] == x)
            return true;
    }
    return false;
}

void insert(int x) {
    if (siz == m) {
        head = (head + 1) % M;
    }
    tail = (tail + 1) % M;
    que[tail] = x;
    if (siz != m) siz += 1;
}

int main() {
    cin >> m >> n;
    int c;
    int ans = 0;
    while (cin >> c) {
        if (find(c)) continue;
        insert(c);
        ans += 1;
    }
    cout << ans << "\n";
}
// 0 -1
// 1, false, 0 0, 1
// 2, false, 0 1, 1 2
// 1,
