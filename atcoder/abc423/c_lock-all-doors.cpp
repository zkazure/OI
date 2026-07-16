#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("./data/c.txt", "r", stdin);
    int n, r;
    int ans = 0; 
    cin >> n >> r;
    int doors[n]= {0};
    for (int i=1; i<=n; ++i)
        cin >> doors[i];

    int idx=1;
    int loc=0, unl=0;
    for (idx=1; idx<=r; ++idx)
        if (doors[idx]==0)
            break;
    for (; idx<=r; ++idx)
        if (doors[idx]==1)
            loc++;
        else unl++;

    for (idx=n; idx>r; --idx)
        if (doors[idx]==0)
            break;

    for (; idx>r; --idx)
        if (doors[idx]==1)
            loc++;
        else unl++;
    
    ans = 2*loc + unl;

    cout << ans;
    fclose(stdin);
    return 0;
}
