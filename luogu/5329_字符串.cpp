#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<char> a; a.push_back('_');
    // char a[n+1];

    for (int i=1; i<=n; ++i) {
        char tmp; cin >> tmp;
        a.push_back(tmp);
    }
    // int n=7; char a[] = {'_', 'a', 'a', 'b', 'a', 'a', 'a', 'b'};

    stack<int> st; st.push(0);
    for (int i=2; i<=n; ++i) {
        if (a[i]>a[i-1]) {
            st.push(i);
            int left=i;
            while (i<n && a[i+1]>a[i]) {
                st.push(i+1);
                i += 1;
            }
            int right=i;
            for (int j=right; j>=left; --j) {
                cout << j << " ";
            }
        }
    }
    st.push(n+1);

    int left = st.top(); st.pop();
    int right;
    while (!st.empty()) {
        right = left;
        left = st.top(); st.pop();
        for (int i=left+1; i<right; ++i) {
            cout << i << " ";
        }
    }

    return 0;
}
