#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string name[n];
    int bir[n];
    int idx[n];

    for (int i=0; i<n; i++) {
        cin >> name[i];
        int y, m, d;
        cin >> y >> m >> d;
        bir[i] = y*10000+m*100+d;
        idx[i] = i;
    }

    for (int i=1; i<n; i++) {
        int tmp = idx[i];
        int j=i-1;
        // for (; j>=0 ; j--) {
        //     if (bir[tmp]<bir[idx[j]]) 
        //         idx[j+1] = idx[j];
        //     else break;
        // }
        for (; j>=0 && bir[tmp]<=bir[idx[j]]; --j)
            idx[j+1] = idx[j];
        idx[j+1] = tmp;
    }

    // ========= bubble sort ============
    // for (int i=0; i<n-1; i++) {
    //     for (int j=i+1; j<n; ++j) {
    //         if (bir[idx[j]]<=bir[idx[i]])
    //             swap(idx[j], idx[i]);
    //     }
    // }

    for (int i=0; i<n; ++i) {
        cout << name[idx[i]] << endl;
    }
    
    return 0; 
}
