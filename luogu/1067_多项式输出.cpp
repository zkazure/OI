// ========= crazy solution =============
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int tmp;
    cin >> n;

    for(int i=n; i>=0; --i) {
        cin >> tmp;
        if (tmp) {
            if (i<n && tmp>0)
                cout << "+";
            if (abs(tmp)>1 || i==0)
                cout << tmp;
            if (tmp==-1 && i)
                cout << "-";
            if (i>0)
                cout << "x";
            if (i>1)
                cout << "^" << i;
        }
    }

    return 0;
}

// // ======= bad solution 2 ============
// #include <bits/stdc++.h>
// #define int long long

// using namespace std;

// signed main() {
//     int n;
//     cin >> n;
//     int cof[105];
//     for (int i=n; i>=0; --i)
//         cin >> cof[i];
//     bool least_one = false;
    
//     for (;n>0; --n) {
//         if (cof[n]) {
//             if (cof[n]==1)
//                 ;
//             else if (cof[n]==-1)
//                 cout << "-";
//             else cout << cof[n];
//             cout << "x^" << n;
//             n--;
//             least_one = true;
//             break;
//         }
//     }

//     for (; n>0; --n) {
//         if (cof[n]) {
//             least_one = true;

//             if (cof[n] > 0) {
//                 cout << "+";
//                 if (cof[n]==1)
//                     ;
//                 else cout << cof[n];
//             } else {
//                 if (cof[n]==-1)
//                     cout << "-";
//                 else cout << cof[n];
//             }
//             cout << "x^" << n;
//         }        
//     }

//     if (cof[0]) {
//         if (cof[0]<0)
//             cout << cof[0];
//         else cout << "+" << cof[0];
//         least_one = true;
//     }

//     if (!least_one)
//         cout << 0;

//     return 0;
// }

// // === bad solution =========
// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     int n;
//     cin >> n;
//     int coef[105];
//     // int coef[7];
//     for (int i=n; i>=0; --i)
//         cin >> coef[i];

//     int idx = n;
//     for (; idx>=0; --idx) {
//         if (coef[idx]) {
//             if (idx) {
//             
//                 cout << coef[idx] << "x^" << idx;
//                 idx--;
//                 break;
//             }
//             else
//                 cout << coef[idx];
//         }
//     }

//     if (idx) {
//         for (; idx>0; --idx) {
//             if (coef[idx] > 0) {
//                 cout << '+';
//                 if (coef[idx]!=1)
//                     cout << coef[idx];
//                 cout << "x^" << idx;
//             }
//             if (coef[idx] < 0) {
//                 if (coef[idx]!=-1)
//                     cout << coef[idx];
//                 else cout << '-';
//                 cout << "x^" << idx;
//             }
//         }
//     }

//     // if (coef[idx]) {
//     //     if (coef[idx] > 0) {
//     //         cout << '+';
//     //         cout << coef[idx];
//     //     }
//     //     if (coef[idx] < 0) {
//     //         cout << coef[idx];
//     //     }        
//     // }
//     if (coef[0]) {
//         if (coef[0] > 0) {
//             cout << '+';
//             cout << coef[0];
//         }
//         if (coef[0] < 0) {
//             cout << coef[0];
//         }        
//     }
    
//     return 0;
// }
