#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (scanf("%d", &n) == 1 && n != 0) {
        while (true) {
            int out[1005];
            scanf("%d", out + 1);
            if (out[1] == 0)
                break;
            for (int i = 2; i <= n; ++i)
                scanf("%d", out + i);

            stack<int> st;
            int cnt = 1, in = 1;
            bool ok = true;
            while (cnt <= n) {
                if (in == out[cnt]) {
                    in++, cnt++;
                } else if (!st.empty() && st.top() == out[cnt]) {
                    st.pop(), cnt++;
                } else if (in <= n) {
                    st.push(in++);
                } else {
                    ok = false;
                    break;
                }
            }
            printf("%s\n", ok ? "Yes" : "No");
        }
        printf("\n");
    }
    return 0;
}
