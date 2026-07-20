#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

struct Mouse {
    int id, w, s;
};

int main() {
    vector<Mouse> mice;
    int cnt = 0;
    int w, s;
    while (cin >> w >> s) {
        mice.push_back({++cnt, w, s});
    }

    sort(mice.begin(), mice.end(),
         [](const Mouse& a, const Mouse& b) {
             if (a.w == b.w) return a.s > b.s;
             return a.w < b.w;
         });

    int n = mice.size();
    if (n == 0) return 0;

    vector<int> dp(n, 1);
    vector<int> pre(n, -1);
    int max_len = 1;
    int end_idx = 0;

    for (int i = 1; i < n; i += 1) {
        for (int j = 0; j < i; j += 1) {
            if (mice[i].w > mice[j].w && mice[i].s < mice[j].s) {
                if (dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    pre[i] = j;
                }
            }
        }
        if (dp[i] > max_len) {
            max_len = dp[i];
            end_idx = i;
        }
    }

    cout << max_len << endl;
    vector<int> path;
    int curr = end_idx;
    while (curr != -1) {
        path.push_back(mice[curr].id);
        curr = pre[curr];
    }
    for (int i = path.size() - 1; i >= 0; i -= 1) {
        cout << path[i] << endl;
    }

    return 0;
}
