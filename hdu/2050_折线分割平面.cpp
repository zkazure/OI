#include <iostream>
using namespace std;

int cal(int n) {
    if (n == 1) return 2;

    return 1 + 4 * (n - 1) + cal(n - 1);
}

int main() {
    int C; cin >> C;
    while (C > 0) {
        int n; cin >> n;

        cout << cal(n) << endl;

        C -= 1;
    }
}
