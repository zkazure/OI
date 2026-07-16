#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int dir[n];
    vector<string> career;

    for (int i=0; i<n; ++i) {
        string tmp; 
        cin >> dir[i] >> tmp;
        career.push_back(tmp);
    }

    int a, b;
    int idx=0;
    for (int i=0; i<m; ++i) {
        cin >> a >> b;

        if (dir[idx] ^ a)
            idx += b;
        else
            idx -= b;
        
        if (idx>=n)
            idx-=n;
        else if (idx<0)
            idx+=n;
    }

    cout << career[idx];
    return 0;
}
