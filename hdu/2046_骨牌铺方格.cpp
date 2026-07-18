#include <iostream>
using namespace std;

const int N = 51;
long long int ans[N];

int main() {
    ans[0] = 0, ans[1] = 1, ans[2] = 2;
    for (int i = 3; i < N; i += 1) ans[i] = ans[i - 1] + ans[i - 2];

    int n;
    while (cin >> n) {
        cout << ans[n] << endl;
    }

    return 0;
}
