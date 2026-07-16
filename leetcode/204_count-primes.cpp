#include <bits/stdc++.h>
using namespace std;

// code_start

class Solution {
public:
    int countPrimes(int n) {
        int cnt = 0;
        vector<bool> primes(n, true);
        for (int i=2; i<n; i+=1) {
            if (primes[i]) {
                cnt++;
                for (int j=i*2; j<n; j+=i) {
                    primes[j] = false;
                }
            }
        }
        return cnt;
    }

};

// code_end

int main() {
    Solution s;
    cout << s.countPrimes(499979);

    return 0;
}
