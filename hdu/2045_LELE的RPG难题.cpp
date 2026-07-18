#include <iomanip>
#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

const int N = 55;
const int BASE = 1e8;

class BigInt {
private:
    vector<int> digits;
public:
    BigInt() = default;
    BigInt(int v) {
        if (v == 0) digits.push_back(0);
        while (v > 0) {
            digits.push_back(v % BASE);
            v /= BASE;
        }
    }
    BigInt operator+(const BigInt &other) {
        int carry = 0;
        int n = digits.size() > other.digits.size() ? digits.size() : other.digits.size();
        BigInt res;

        for (int i = 0; i < n || carry != 0; i += 1) {
            int sum = carry;
            if (i < digits.size()) sum += digits[i];
            if (i < other.digits.size()) sum += other.digits[i];

            res.digits.push_back(sum % BASE);
            carry = sum / BASE;
        }
        return res;
    }
    BigInt operator*(const int x) {
        int carry = 0;
        BigInt res;
        for (int i = 0; i < digits.size() || carry != 0; i += 1) {
            int sum = carry;
            if (i < digits.size()) sum += digits[i] * 2;
            res.digits.push_back(sum % BASE);
            carry = sum / BASE;
        }
        return res;
    }

    friend ostream& operator<<(ostream&, const BigInt&);
};

ostream& operator<<(ostream& out, const BigInt& num) {
    out << num.digits.back();

    for (int i = num.digits.size() - 2; i >= 0; i -= 1) {
        out << setfill('0') << setw(8) << num.digits[i];
    }
    return out;
}

BigInt ans[N];

int main() {
    ans[0] = 0, ans[1] = 3, ans[2] = 6, ans[3] = 6;
    for (int i = 4; i < N; i += 1) {
        ans[i] = ans[i - 1] + ans[i - 2] * 2;
    }

    int n;
    while (cin >> n) {
        cout << ans[n] << endl;
    }

    return 0;
}
