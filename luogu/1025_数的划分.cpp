// // ======= crazy solution ===========
// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     int n, k;
//     cin >> n >> k;
//     int dp[205][10] = {0};
//     dp[]
// }

// ========= my solution1 =========
// this is right, but too easy to TLE
#include <bits/stdc++.h>
using namespace std;

int cnt_ways(int n, int k, int cnt) {
    if (cnt==1 && n>k) 
        return 0;
    if (cnt < 0)
        return 0;
    if (k==0)
        return 0;
    if (n<0)
        return 0;
    if (n==0 && cnt==0)
        return 1;

    return cnt_ways(n-k, k, cnt-1) + cnt_ways(n, k-1, cnt);
}

int main() {
    int n, k;
    cin >> n >> k;

    int ways = cnt_ways(n, n, k);
    cout << ways;
}
