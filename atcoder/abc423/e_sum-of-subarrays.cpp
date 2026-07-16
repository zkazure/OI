#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
    freopen("./data/e.txt", "r", stdin);
    int n, q;
    cin >> n >> q;
    // vector<int> a;
    int a[n] = {0};
    for (int i=0; i<n; ++i) {
        // int tmp;
        // cin >> tmp;
        // a.push_back(tmp);
        cin >> a[i];
    }

    vector<int> pre(0, n+1);
    for (int i=1; i<=n; ++i)
        pre[i] = pre[i-1] + a[i-1];

    for (int i=1; i<=n; ++i)
        pre[i] = pre[i-1] + pre[i];
    for (int i=1; i<n; ++i)
        pre[i] = pre[i-1] + pre[i];

    for (int i=0; i<q; ++i) {
        int l, r;
        cin >> l >> r;
        cout << pre[r] - pre[l-1] << '\n';
    }

    fclose(stdin);
    return 0;
}
