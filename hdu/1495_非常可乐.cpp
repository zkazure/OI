#include <queue>
#include <iostream>
using namespace std;

int S, N, M;
const int MAXNM = 105;
int vis[MAXNM][MAXNM];

struct Cola {
    int s, n, m, cnt;

    Cola() : s(0), n(0), m(0), cnt(0) {}
    Cola(int s, int n, int m, int cnt) : s(s), n(n), m(m), cnt(cnt) {}

    bool equal_divided() {
        int half = S / 2;
        if (s == n && half == s ||
            s == m && half == s ||
            m == n && half == m)
            return true;

        return false;
    }
    void print() {
        cout << "Cola: "
        << s << " " << n << " " << m << " " << cnt
        << endl;
    }
};

void bfs() {
    Cola cola(S, 0, 0, 0);
    if (S % 2) {
        cout << "NO" << endl;
        return;
    }

    queue<Cola> q;
    q.push(cola);
    while (!q.empty()) {
        Cola curr = q.front();
        q.pop();
        // curr.print();

        if (vis[curr.n][curr.m]) continue;
        vis[curr.n][curr.m] = true;

        if (curr.equal_divided()) {
            cout << curr.cnt << endl;
            return;
        }

        if (curr.s) {
            if (curr.n < N) {
                int tmp = (N-curr.n > curr.s) ? curr.s : N-curr.n;
                q.push(Cola(curr.s-tmp, curr.n+tmp, curr.m, curr.cnt+1));
            }
            if (curr.m < M) {
                int tmp = (M-curr.m > curr.s) ? curr.s : M-curr.m;
                q.push(Cola(curr.s-tmp, curr.n, curr.m+tmp, curr.cnt+1));
            }
        }
        if (curr.m) {
            if (curr.s < S) {
                int tmp = (S-curr.s > curr.m) ? curr.m : S-curr.s;
                q.push(Cola(curr.s+tmp, curr.n, curr.m-tmp, curr.cnt+1));
            }
            if (curr.n < N) {
                int tmp = (N-curr.n > curr.m) ? curr.m : N-curr.n;
                q.push(Cola(curr.s, curr.n+tmp, curr.m-tmp, curr.cnt+1));
            }
        }
        if (curr.n) {
            if (curr.s < S) {
                int tmp = (S-curr.s > curr.n) ? curr.n : S-curr.s;
                q.push(Cola(curr.s+tmp, curr.n-tmp, curr.m, curr.cnt+1));
            }
            if (curr.m < M) {
                int tmp = (M-curr.m > curr.n) ? curr.n : M-curr.m;
                q.push(Cola(curr.s, curr.n-tmp, curr.m+tmp, curr.cnt+1));
            }
        }
    }

    cout << "NO\n";
}

int main() {
    while (cin >> S >> N >> M &&
           S && N && M) {
        for (int i = 0; i < MAXNM; i += 1) {
            for (int j = 0; j < MAXNM; j += 1) {
                vis[i][j] = false;
            }
        }

        bfs();
    }
}
