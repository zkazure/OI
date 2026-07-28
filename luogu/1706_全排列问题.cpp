#include <iomanip>
#include <iostream>
using namespace std;

const int MAXN = 9;
int ans[MAXN + 1];
int vis[MAXN + 1];
int n;

void dfs(int step) {
    if (step > n) {
        for (int i = 1; i <= n; i += 1) {
            cout << setw(5) << ans[i];
        }
        cout << "\n";
    }

    for (int i = 1; i <= n; i += 1) {
        if (vis[i] == false) {
            ans[step] = i;
            vis[i] = true;
            dfs(step + 1);
            vis[i] = false;
        }
    }
}

int main() {
    cin >> n;

    dfs(1);
}
