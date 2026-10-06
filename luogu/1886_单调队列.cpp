#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int a[N];
deque<int> q;

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a+i);

    for (int i = 1; i <= n; ++i) {
        while (!q.empty() && a[q.back()] > a[i])
            q.pop_back();
        q.push_back(i);
        if (i >= k) {
            if (!q.empty() && q.front() <= i-k)
                q.pop_front();
            printf("%d ", a[q.front()]);
        }
    }
    printf("\n");

    while (!q.empty()) q.pop_back();
    for (int i = 1; i <= n; ++i) {
        while (!q.empty() && a[q.back()] < a[i])
            q.pop_back();
        q.push_back(i);
        if (i >= k) {
            if (!q.empty() && q.front() <= i-k)
                q.pop_front();
            printf("%d ", a[q.front()]);
        }
    }

    return 0;
}
