// ======== crazy solution ============
#include <bits/stdc++.h>
using namespace std;

int main() {
    string n;
    int k;
    cin >> n >> k;

    while (k) {
        int i=0;
        // if (i== n.size()-2)
        //     break;
        while (n[i]<=n[i+1])
            ++i;
        n.erase(i, 1);
        k--;
    }

    // while (k) {
    //     int i=n.size()-1;
    //     n.erase(i, 1);
    //     k--;
    // }

    while (n[0]=='0' && n.size()>1)
        n.erase(0, 1);

    cout << n;
    return 0;
}

// ========= my bad solution ====================
#include <bits/stdc++.h>
#define N 250
using namespace std;

int main() {
    int n[N], k;
    memset(n, -1, N);

    for (int i=N-1; i>=0; --i) {
        cin >> n[i];
    }
    cin >> k;

    int cnt = 0;

    for (int i=N-1; i>=0; --i) {
        if (cnt>=k)
            break;
        if (n[i]>=0) {
            for (int j=i-1; j>=0; --j) {
                if (n[j]>=0 && n[i]>n[j]) {
                    n[i] = -1;
                    cnt++;
                    break;
                }
            }
        }
    }

    while (cnt < k) {
        for (int i=0; i<N; ++i) {
            if (n[i]>=0)
                n[i]=-1;
        }
    }

    for (int i=N-1; i>=0; --i) {
        if (n[i]>=0)
            cout << n[i];
    }

    return 0;
}
