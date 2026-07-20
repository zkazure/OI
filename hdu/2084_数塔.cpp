#include <algorithm>
#include <iostream>
using namespace std;

int nums[50 * 101];

int main() {
    int C, N; cin >> C;
    while (C > 0) {
        cin >> N;
        for (int i = 0; i < N; i += 1) {
            for (int j = 0; j <= i; j += 1) {
                cin >> nums[(i+1)*i/2 + j];
            }
        }

        for (int i = N-2; i >= 0; i -= 1) {
            for (int j = 0; j <= i; j += 1) {
                nums[i*(i+1)/2 + j] += max(nums[(i+1)*(i+2)/2 + j], nums[(i+1)*(i+2)/2 + j+1]);
            }
        }
        cout << nums[0] << endl;

        C -= 1;
    }
}
