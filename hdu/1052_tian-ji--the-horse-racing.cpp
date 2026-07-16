#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<int> tian(n);
        vector<int> qi(n);
        for (int i = 0; i < n; i += 1) {
            cin >> tian[i];
        }
        for (int i = 0; i < n; i += 1) {
            cin >> qi[i];
        }
        sort(tian.begin(), tian.end(), [](const int &a, const int &b) { return a > b; });
        sort(qi.begin(), qi.end(), [](const int &a, const int &b) { return a > b; });

        int tl = 0, tr = n - 1;
        int ql = 0, qr = n - 1;
        int ans = 0;
        while (tl <= tr) {
            if (tian[tl] > qi[ql]) {
                ans += 200;
                tl += 1, ql += 1;
            } else if (tian[tl] == qi[ql]) {
                if (tian[tr] < qi[qr]) {
                    ans -= 200;
                    tr -= 1, ql += 1;
                } else {
                    tl += 1, ql += 1;
                }
            } else {
                ans -= 200;
                tr -= 1;
                ql += 1;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
