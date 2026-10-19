#include <string>
using namespace std;

// code_start

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows > s.length()) {
            return s;
        }

        string res = "";
        int cycle = 2 * numRows - 2;
        for (int i = 0; i < numRows; ++i) {
            for (int j = i; j < s.length(); j += cycle) {
                res += s[j];

                int mid = j + cycle - 2*i;
                if (i != 0 && i != numRows-1 && mid < s.length()) {
                    res += s[mid];
                }
            }
        }

        return res;
    }
};


class mySolution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        string res = "";
        for (int k = 0; k < numRows && k < s.length(); ++k) {
            int idx = k;
            res += s[idx];
            int special = numRows-k-2;
            int forward = 2*special+2;
            idx += forward;
            while (idx < s.length()) {
                if (idx < s.length()) {
                    if (forward != 0) {
                        res += s[idx];
                    }
                    special = numRows-special-3;
                    forward = 2 * special + 2;
                    idx += forward;
                }
            }
        }

        return res;
    }
};

// code_end
