#include <bits/stdc++.h>
using namespace std;

int main() {
    int m;
    cin >> m;
    int fib[10000000] = {0};
    fib[1] = 1;
    int idx = 0;
    for (int i=2; ; i++) {
        fib[i] = fib[i-1] + fib[i-2];
        fib[i] %= m;
        if (fib[i]==1 && fib[i-1]==0) {
            idx=i-1;
            break; 
        }
    }

    cout << idx;
    return 0;
}
