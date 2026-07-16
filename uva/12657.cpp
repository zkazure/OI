// moving box

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
int n, m;
int Left[MAXN], Right[MAXN];
int oper, x, y;
bool invert = false;
long long res = 0;
int case_num = 1;

void init() {
    Right[0] = 1;
    Left[n + 1] = n;
    invert = false;
    res = 0;

    for (int i = 1; i <= n; ++i) {
        Left[i] = i - 1;
        Right[i] = i + 1;
    }
}

void link(int l, int r) {
    Right[l] = r;
    Left[r] = l;
}

void oper1() {
    scanf("%d%d", &x, &y);

    if (!invert) {
        if (Left[y] == x)
            return;
        link(Left[x], Right[x]);
        link(Left[y], x);
        link(x, y);
    } else {
        if (Right[y] == x)
            return;
        link(Left[x], Right[x]);
        link(x, Right[y]);
        link(y, x);
    }
}

void oper2() {
    scanf("%d%d", &x, &y);


    if (!invert) {
        if (Right[y] == x)
            return;
        link(Left[x], Right[x]);
        link(x, Right[y]);
        link(y, x);
    } else {
        if (Left[y] == x)
            return;
        link(Left[x], Right[x]);
        link(Left[y], x);
        link(x, y);
    }
}

void oper3() {
    scanf("%d%d", &x, &y);

    if (Right[x] == y) {
        int ry = Right[y];
        link(Left[x], y);
        link(x, ry);
        link(y, x);
    } else if (Left[x] == y) {
        int rx = Right[x];
        link(Left[y], x);
        link(y, rx);
        link(x, y);
    } else {
        int ly = Left[y];
        int ry = Right[y];

        link(Left[x], y);
        link(y, Right[x]);
        link(ly, x);
        link(x, ry);
    }
}

void oper4() {
    invert = !invert;
}

void operations() {
    scanf("%d", &oper);
    switch (oper) {
    case 1: {
        oper1();
        break;
    }
    case 2: {
        oper2();
        break;
    }
    case 3: {
        oper3();
        break;
    }
    case 4: {
        oper4();
        break;
    }
    }
}

void output() {
    int idx = 0;
    if (invert) {
        // right to left
        for (int i = 1, idx = Left[n+1]; i <= n; ++i, idx = Left[idx]) {
            if (i % 2)
                res += idx;
        }
    } else {
        // left to right
        for (int i = 1, idx = Right[0]; i <= n; ++i, idx = Right[idx]) {
            if (i % 2)
                res += idx;
        }
    }

    printf("Case %d: %lld\n", case_num, res);
}

int main() {
    while (scanf("%d", &n) == 1) {
        init();
        scanf("%d", &m);
        for (int _ = 0; _ < m; ++_) {
            operations();
        }
        output();
        case_num += 1;
    }
}
