#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int villages[101];

int find(int x) {
    if (x != villages[x])
        villages[x] = find(villages[x]);
    return villages[x];
}

void merge(int a, int b) {
    villages[find(b)] = find(a);
}

int main() {
    int N;
    while (cin >> N && N != 0) {
        for (int i = 1; i <= N; i += 1) villages[i] = i;

        int num = N * (N - 1) / 2;
        vector<vector<int>> roads(num, vector<int>(3));
        for (int i = 0; i < num; i += 1) {
            for (int j = 0; j < 3; j += 1)
                cin >> roads[i][j];
        }
        sort(roads.begin(), roads.end(),
             [](const vector<int> &a, const vector<int> &b) {
                 return a[2] < b[2];
             });

        int ans = 0;
        for (int i = 0; i < num; i += 1) {
            int a = roads[i][0], b = roads[i][1];
            if (find(a) != find(b)) {
                merge(a, b);
                ans += roads[i][2];
            }
        }
        cout << ans << endl;
    }
}
