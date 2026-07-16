// ====== crazy solution =======
#include <bits/stdc++.h>
using namespace std;

int count(const int& n) {
    int a, b, ans = 0;
    for (int i=1; i<=n; i*=10) {
        a = n/i, b = n%i;
        ans += (a+7)/10*i + (a%10==2)*(b+1);
    }
    return ans;
}

int main() {
    int l, r;
    cin >> l >> r;
    cout << count(r) - count(l-1);
    return 0;
}


// ====== my solution ======
#include <bits/stdc++.h>
using namespace std;

int cnt_2(int n) {
    int cnt = 0;
    while (n!=0) {
        if (n%10 == 2)
            cnt ++;
        n/=10;
    }
    return cnt;
}

int main() {
    int l, r;
    int cnt = 0;
    cin >> l >> r;
    for (int i=l; i<=r; i++) {
        cnt += cnt_2(i);
    }

    cout << cnt;
    return 0;
}
