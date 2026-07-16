// ============ crazy solution ==============
/*
  1. 每个数都是丑数
  2. 每个数都可能 * 2/3/5
  3. 每次选最小
*/
#include <bits/stdc++.h>
using namespace std;

#define N = 1000000

int min_3(int& a, int& b, int& c) {
    if (a<b)
        return a<c ? a: c;
    else
        return b<c ? b: c;
}
int main() {
    int ugly[1500] = {0};
    ugly[0] = 1;

    int u2=2, u3=3, u5=5;
    int p2=0, p3=0, p5=0;

    for (int i=1; i<1500; ++i) {
        ugly[i] = min_3(u2, u3, u5);

        if (ugly[i]==u2)
            u2 = ugly[++p2]*2;
        if (ugly[i]==u3)
            u3 = ugly[++p3]*3;
        if (ugly[i]==u5)
            u5 = ugly[++p5]*5;
    }

    cout << ugly[1499];
}



// ============== my solution ===============

#include <bits/stdc++.h>
#define N 1000000000
using namespace std;

bool is_ugly(long long& n, vector<int> ugly) {
    if (n%2==0 && ugly[n/2]==1) {
        return true;
    } else if (n%3==0 && ugly[n/3]==1) {
        return true;
    } else if (n%5==0 && ugly[n/5]==1) {
        return true;
    }

    return false;    
}
int main() {
    // const long long N = 100000;
    // int idx[N] = {0, 1, 1, 1, 1, 1, 1, 0};
    vector<int> idx(N, 0);
    idx[1] = 1;
    idx[2] = 1;
    idx[3] = 1;
    idx[4] = 1;
    idx[5] = 1;
    
    int cnt = 5;

    for (long long i=6; i<N ; ++i) {
        if (is_ugly(i, idx)) {
            idx[i] = 1;
            cnt ++;

            if (cnt==500) {
                cout << i;
                break;
            }
        }
    }
    
    return 0;
}
