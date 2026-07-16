#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {
    int M, N;
    while (cin >> M >> N) {
        if (M == -1 && N == -1) break;

        vector<pair<int, int>> rooms(N);
        for (int i = 0; i < N; i += 1) {
            cin >> rooms[i].first >> rooms[i].second;
        }

        using ElementType = decltype(rooms)::value_type;
        sort(rooms.begin(), rooms.end(),
             [](const ElementType &a, const ElementType &b) {
                 double ar = static_cast<double>(a.first) / a.second;
                 double br = static_cast<double>(b.first) / b.second;
                 return ar > br;
             });

        double rest = M;
        double ans = 0;
        for (int i = 0; i < N; i += 1) {
            if (rest < rooms[i].second) {
                ans += static_cast<double>(rooms[i].first) / rooms[i].second * rest;
                rest = 0;
                break;
            }

            ans += rooms[i].first;
            rest -= rooms[i].second;
        }
        cout << fixed << setprecision(3) << ans << endl;
    }

    return 0;
}
