#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

const int T = 100000;
const int LEN = 11;
int pies[LEN * T];

int coord(int t, int x) { return t * LEN + x; }

int main() {
    int n;
    while (cin >> n && n != 0) {
        memset(pies, 0, sizeof(pies));

        for (int i = 0; i < n; i += 1) {
            int t, x;
            cin >> x >> t;
            pies[coord(t, x)] += 1;
        }
        
        for (int i = T - 2; i >= 0; i -= 1) {
            pies[coord(i, 0)] += max(pies[coord(i + 1, 0)],
                                     pies[coord(i + 1, 1)]);

            for (int j = 1; j < LEN-1; j += 1) {
                pies[coord(i, j)] += max(pies[coord(i+1, j-1)],
                                         max(pies[coord(i+1, j)],
                                             pies[coord(i+1, j+1)]));
            }

            pies[coord(i, LEN-1)] += max(pies[coord(i + 1, LEN-1)],
                                         pies[coord(i + 1, LEN-2)]);
        }

        cout << pies[coord(0, 5)] << endl;
    }

    return 0;
}
