#include <iomanip>
#include <vector>
#include <iostream>
using namespace std;

const int BASE = 1e8;
const int N = 1005;

struct BigInt {
private:
    vector<int> digits;
public:
    BigInt() = default;
    BigInt(int num) {
        if (num == 0) digits.push_back(0);

        while (num > 0) {
            digits.push_back(num % BASE);
            num /= BASE;
        }
    }
    BigInt operator+(const BigInt &other) {
        int carry = 0;
        BigInt res;
        int n = digits.size() > other.digits.size() ? digits.size() : other.digits.size();
        for (int i = 0; i < n || carry != 0; i += 1) {
            int sum = carry;
            if (i < digits.size()) sum += digits[i];
            if (i < other.digits.size()) sum += other.digits[i];
            carry = sum / BASE;
            res.digits.push_back(sum % BASE);
        }

        return res;
    }

    friend ostream& operator<<(ostream &, const BigInt &);
};

ostream& operator<<(ostream &out, const BigInt &num) {
    out << num.digits.back();

    for (int i = num.digits.size() - 2; i >= 0; i -= 1) {
        out << setfill('0') << setw(8) << num.digits[i];
    }
    return out;
}

BigInt ans[N];

int main() {
    ans[0] = 0, ans[1] = 1, ans[2] = 2, ans[3] = 4, ans[4] = 7;
    for (int i = 5; i < N; i += 1) {
        ans[i] = ans[i - 1] + ans[i - 2] + ans[i - 4];
    }

    int n;
    while (cin >> n) {
        cout << ans[n] << endl;
    }
}
