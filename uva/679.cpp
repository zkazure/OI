// dropping balls

#include <bits/stdc++.h>
using namespace std;

const int maxd = 20;
const int n = 1 << maxd;
int D, I;
int k;

int main() {
    int t; scanf("%d", &t);

    while (t--) {
        scanf("%d%d", &D, &I);
        k = 1;
        for (int i = 1; i < D; ++i) {
            if (I % 2) {
                k *= 2;
                I = (I + 1) / 2;
            } else {
                k = k * 2 + 1;
                I /= 2;
            }
        }
        printf("%d\n", k);
    }
}
