#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int main() {
    // freopen("./data/a.txt", "r", stdin);
    // int x = 65000, c=8;
    
    int x, c;
    cin >> x >> c;

    int ans = x/(1000+c)*1000;
    cout << ans;

    // fclose(stdin);
    return 0;
}
