#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int main() {
    vector<string> rooms;
    int n;
    cin >> n;
    for (int i=0; i<n; ++i) {
        string tmp;
        cin >> tmp;
        rooms.push_back(tmp);
    }

    int x;
    string y;
    cin >> x >> y;
    if (rooms[x-1] == y)
        printf("Yes");
    else printf("No");

    return 0;
}
