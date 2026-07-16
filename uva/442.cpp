#include <bits/stdc++.h>
using namespace std;

struct Matrix {
    int a, b;
    Matrix(int a=0, int b=0) : a(a), b(b) {}
} m[26];

int n;

int get_index(int x) {
    return x - 'A';
}

int main() {
    // get matrix
    cin >> n;
    for (int i = 0; i < n; ++i) {
        char x; cin >> x;
        cin >> m[get_index(x)].a >> m[get_index(x)].b;
    }

    // test
    string input;
    while (cin >> input) {
        stack<Matrix> s;
        int ans = 0;
        int len = input.length();
        bool error = false;
        for (int i = 0; i < len; ++i) {
            if (isalpha(input[i])) {
                s.push(m[get_index(input[i])]);
            } else if (input[i] == ')') {
                Matrix y = s.top(); s.pop();
                Matrix x = s.top(); s.pop();
                if (x.b != y.a) {
                    error = true;
                    break;
                }
                ans += x.a * x.b * y.b;
                s.push(Matrix(x.a, y.b));
            }
        }
        if (error)
            printf("error\n");
        else
            printf("%d\n", ans);
    }
    return 0;
}
