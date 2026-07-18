#include <iostream>
#include <vector>

using namespace std;

// Custom struct to handle numbers up to ~100 digits
struct BigInt {
    vector<int> digits;

    // Constructor
    BigInt(int v = 0) {
        if (v == 0) digits.push_back(0);
        while (v > 0) {
            digits.push_back(v % 10);
            v /= 10;
        }
    }

    // Multiply BigInt by a standard integer
    void multiply(int x) {
        int carry = 0;
        for (size_t i = 0; i < digits.size(); ++i) {
            long long cur = (long long)digits[i] * x + carry;
            digits[i] = cur % 10;
            carry = cur / 10;
        }
        while (carry > 0) {
            digits.push_back(carry % 10);
            carry /= 10;
        }
    }

    // Divide BigInt by a standard integer
    void divide(int x) {
        int rem = 0;
        for (int i = (int)digits.size() - 1; i >= 0; --i) {
            long long cur = digits[i] + (long long)rem * 10;
            digits[i] = cur / x;
            rem = cur % x;
        }
        // Remove leading zeros
        while (digits.size() > 1 && digits.back() == 0) {
            digits.pop_back();
        }
    }

    // Print the BigInt
    void print() const {
        for (int i = (int)digits.size() - 1; i >= 0; --i) {
            cout << digits[i];
        }
        cout << "\n";
    }
};

BigInt C[105];

int main() {
    // Precompute Catalan numbers from 1 to 100
    C[1] = BigInt(1);
    for (int i = 2; i <= 100; ++i) {
        C[i] = C[i - 1];
        C[i].multiply(4 * i - 2);
        C[i].divide(i + 1);
    }

    int n;
    // Read until EOF and terminate on -1
    while (cin >> n && n != -1) {
        C[n].print();
    }
    
    return 0;
}
