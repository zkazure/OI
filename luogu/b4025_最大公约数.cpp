#include <bits/stdc++.h>
using namespace std;

int find_gcd(int a, int b) {
    if(b)
        return find_gcd(b, a%b);
    return a;
}

int main() {
    int a, b;
    cin >> a >> b;
    int ans;
    if (a>b)
        ans = find_gcd(a, b);
    else
        ans = find_gcd(b, a);
    cout << ans;
    return 0;
}
