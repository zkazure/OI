#include <bits/stdc++.h>
using namespace std;


int main() {
    int game[5][5] = {0, -1, 1, 1, -1,
                      1, 0, -1, 1, -1,
                      -1, 1, 0, -1, 1,
                      -1, -1, 1, 0, 1,
                      1, 1, -1, -1, 0};
    int n, na, nb;
    cin >> n >> na >> nb;
    int a[na], b[nb];
    for (int i=0; i<na; ++i) cin >> a[i];
    for (int i=0; i<nb; ++i) cin >> b[i];

    int ca=0, cb=0;
    int a_win=0, a_lose=0;
    while(n) {
        if (ca > na-1) ca=0;
        if (cb > nb-1) cb=0;

        int tmp = game[a[ca]][b[cb]];
        if (tmp==1)
            a_win ++;
        else if (tmp==-1)
            a_lose ++;

        ca++, cb++;
        n--;
    }

    cout << a_win << " " << a_lose << endl;

    return 0;
}
