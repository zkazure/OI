#include <bits/stdc++.h>
using namespace std;

const int N = (int) 2e6+5;
int n, m;
int a[N];
deque<int> q;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        if (q.empty())
            cout << 0;
        else
            cout << a[q.front()];
        cout << "\n";

        while (!q.empty() && a[i] < a[q.back()])
            q.pop_back();
        q.push_back(i);
        if (i-m >= q.front())
            q.pop_front();
    }
}
