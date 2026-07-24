#include <algorithm>
#include <iostream>
using namespace std;

const int MAXNV = 1005;

struct Bone {
    int value;
    int volume;
};

Bone bones[MAXNV];
int dp[MAXNV];
int T, N, V;

int algo() {
    sort(bones + 1, bones + N + 1,
         [](const Bone& a, const Bone& b) {
             return a.volume == b.volume
                    ? a.value > b.value
                    : a.volume < b.volume;
         });

    for (int i = 0; i <= V; i += 1) dp[i] = 0;

    for (int i = 1; i <= N; i += 1) {
        for (int j = V; j >= bones[i].volume; j -= 1) {
            dp[j] = max(dp[j], dp[j - bones[i].volume] + bones[i].value);
        }
    }

    return dp[V];
}

int main() {
    cin >> T;
    while (T > 0) {
        cin >> N >> V;
        for (int i = 1; i <= N; i += 1) {
            cin >> bones[i].value;
        }
        for (int i = 1; i <= N; i += 1) {
            cin >> bones[i].volume;
        }

        cout << algo() << endl;

        T -= 1;
    }
}
