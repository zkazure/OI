#include <bits/stdc++.h>
using namespace std;

struct Square {
private:
    int N;
    vector<vector<int>> s;
public:
    Square(int& n)
    : N(n) {
        s.resize(N);
        for (int i=0; i<N; ++i)
            s[i].resize(N, 0);
    }
    // void next(int& row, int& col) {
    //     if (row==0) {
    //         if (col!=N-1)
    //             row=N-1, col++;
    //         else row++;
    //     } else {
    //         if (col==N-1)
    //             row--, col=0;
    //         else {
    //             if (s[row+1][col+1]==0)
    //                 row++, col++;
    //             else row++;
    //         }
    //     }
    // }
    void next(int& row, int& col) {
        if (row==0 && col!=N-1)
            row=N-1, col++;
        else if (col==N-1 && row!=0)
            row--, col=0;
        else if (row==0 && col==N-1)
            row ++;
        else if (row!=0 && col!=N-1) {
            if (s[row-1][col+1]==0)
                row--, col++;
            else row++;
        }
    }
     void set(const int& row, const int& col, const int& x) {
        s[row][col] = x;
    }
    void set_next(int& row, int& col, const int& x) {
        next(row, col);
        set(row, col, x);
    }
    void print() {
        for (int i=0; i<N; ++i) {
            for (int j=0; j<N; ++j)
                printf("%d ", s[i][j]);
            printf("\n");
        }

    }
};

int main() {
    int n;
    cin >> n;
    Square s(n);
    int row=0, col=n/2;
    s.set(row, col, 1);

    for (int x=2; x<=n*n; ++x) {
        s.set_next(row, col, x);
    }

    s.print();

    return 0;
}
