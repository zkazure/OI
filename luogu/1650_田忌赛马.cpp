#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int tian[n], king[n];
    for (int i=0; i<n; i++)
        cin >> tian[i];
    for (int i=0; i<n; i++)
        cin >> king[i];
    sort(tian, tian+n); sort(king, king+n);

    int cnt = 0;
    int* tl = tian, *tr = tian+(n-1);
    int* kl = king, *kr = king+(n-1);

    while (tl <= tr) {
        // problem is here
        // you can not sacrifice you horse directly 
        // you can draw rather than lose
        // if (*tr > *kr) {
        //     cnt++;
        //     tr--, kr--;
        // } else {
        //     if (*tl<*kr)
        //         cnt--;
        //     tl++, kr--;
        // }
        if (*tr > *kr) {
            cnt++;
            tr--, kr--;
        } else if (*tl > *kl) {
            cnt++;
            tl++, kl++; 
        } else {
            if (*tl < *kr)
                cnt--;
            tl++, kr--;
        }
    }

    int ans = cnt * 200;
    cout << ans << endl;
    return 0;
}
