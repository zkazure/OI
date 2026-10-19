#include <stack>
#include <iostream>
using namespace std;

int n;
const int MAXN = 1e6 + 5;
int h[MAXN], ans[MAXN];
stack<int> st;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> h[i];
        while (!st.empty() && h[st.top()] < h[i]) {
            ans[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << "\n";
    }

    return 0;
}
