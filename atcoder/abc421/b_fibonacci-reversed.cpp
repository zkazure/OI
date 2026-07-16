#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

long long rev_num(int n) {
    long long tmp = 0;
    while(n) {
        tmp = tmp*10 + n%10;
        n/=10;
    }
    return tmp; 
}

int main() {
    long long a[10];
    cin >> a[0] >> a[1];

    for (int i=2; i<10; ++i)
        a[i] = rev_num(a[i-1] + a[i-2]);

    printf("%lld", a[9]);

    return 0;
}
