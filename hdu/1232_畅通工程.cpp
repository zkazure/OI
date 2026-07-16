#include <set>
#include <iostream>
using namespace std;

int citys[1001];

int find(int x) {
    if (x != citys[x])
        citys[x] = find(citys[x]);
    return citys[x];
}

void merge(int a, int b) {
    if (a != b)
        citys[find(b)] = find(a);
}

int main() {
    int N, M;
    while (cin >> N >> M && N != 0) {
        set<int> s;
        for (int i = 1; i <= N; i += 1) {
            citys[i] = i;
        }

        for (int i = 0; i < M; i += 1) {
            int x, y; cin >> x >> y;
            merge(x, y);
        }

        for (int i = 1; i <= N; i += 1) {
            citys[i] = find(i);
            s.insert(find(i));
        }
        cout << s.size() - 1 << endl;
    }
}
