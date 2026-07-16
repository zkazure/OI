// it is easy for min
// but max is difficult

#include <bits/stdc++.h>
using namespace std;

int max_time(int& l, int* left, int* right) {
    if (left>right)
        return 0;
    int num = left-right;
    
    if (num==1) {
        int mid = (*right-*left);
        int lt = *left;
        int rt = l+1-*right;
        return mid+ ( (lt>rt) ? lt : rt );
    }
}

int main() {
    int l, n;
    cin >> l >> n;
    int a[n];
    for (int i=0; i<n; ++i)
        cin >> a[i]; 
    
}
