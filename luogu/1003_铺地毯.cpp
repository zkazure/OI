#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int bg[n][4];
    for (int i=0; i<n; i++) {
        cin >> bg[i][0] >> bg[i][1];
        int tmp; cin >> tmp >> tmp;
        bg[i][2] = bg[i][0] + tmp;
        bg[i][3] = bg[i][1] + tmp; 
    }

    int x, y;
    cin >> x >> y;
    for (int i=n-1; i>=0; --i) {
        if (x<=bg[i][2] && x>=bg[i][0]
            && y<=bg[i][3] && y>=bg[i][1]) {
            cout << i+1;
            return 0;
        }
    }

    return 0;
}

// // MLE
// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     int n;
//     cin >> n;
//     int bg[100][100];
//     // int bg[n+1][n+1];    
//     memset(bg, -1, sizeof(bg));

//     for (int i=1; i<=n; i++) {
//         int a, b, c, d;
//         cin >> a >> b >> c >> d;
//         for (int j=a; j<=a+c; j++) {
//             for (int k=b; k<=b+d; k++) {
//                 bg[j][k] = i;
//             }
//         }
//     }

//     int x, y;
//     cin >> x >> y;
//     cout << bg[x][y];

//     return 0;
// }
