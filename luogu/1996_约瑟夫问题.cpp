#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    // int n = 10, m = 3;

    queue<int> a;
    for (int i=1; i<=n; ++i)
        a.push(i);

    int cnt = 1;
    while(!a.empty()) {
        if (cnt==m) {
            cout << a.front() << " ";
            a.pop();
            cnt = 1;
        } else {
            a.push(a.front());
            a.pop();
            cnt ++;
        }
    }
    return 0;
}
