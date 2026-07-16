#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string doors = "0";
    for (int i=0; i<n; ++i) {
        char c;
        cin >> c;
        doors += c;
    }

    int left = doors.find("1");
    int right = doors.find_last_of("1");
    cout << right - left;
}

int main() {
    freopen("./data/b.txt", "r", stdin);

    int n;
    vector<int> lock(n+1);
    cin >> n;
    for (int i=1; i<=n; ++i) {
        cin >> lock[i];
    }

    int left=1, right=n;
    while (left<right) {
        if (lock[left]==0)
            left++;
        else if (lock[right]==0)
            right--;
        else break;
    }

    // cout << left << " " << right << endl;
    cout << right - left;

    // solve();
    
    fclose(stdin);
    return 0;
}
