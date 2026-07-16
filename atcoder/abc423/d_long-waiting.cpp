#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    int cur = 0;
    int time = 0;
    for (int i=0; i<n; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        while (cur+c > k) {
            time = pq.top().first;
            cur -= pq.top().second;
            pq.pop();
        }
        int ans = max(a, time);
        cout << ans << '\n';
        pq.emplace(ans+b, c);
        cur += c;
    }
    return 0;
}
