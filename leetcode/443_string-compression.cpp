#include <vector>
#include <string>
using namespace std;

// code_start

class Solution {
public:
    int compress(vector<char> &chars) {
        int ans = 0;

        for (int i = 0; i < chars.size();) {
            const char letter = chars[i];

            int cnt = 0;
            while (letter == chars[i]) {
                cnt += 1;
                i += 1;
            }

            chars[ans++] = letter;
            for (const char &n : to_string(cnt)) {
                chars[ans++] = n;
            }
        }

        return ans;
    }
};

class mySolution {
public:
    int compress(vector<char>& chars) {
        int res = 0;

        char c = chars[0];
        int cnt = 1;
        int idx = 0;            // 正在压缩的第一个 char
        for (int i = 1; i < chars.size(); ++i) {
            if (chars[i] != c) {
                c = chars[i];

                // compress chars
                res += 1;
                chars[idx] = chars[i-1];
                idx += 1;
                if (cnt != 1) {
                    int max = 10;
                    while (max < cnt) {
                        max *= 10;
                    }
                    while (max >= 10) {
                        max /= 10;
                        chars[idx++] = cnt / max + '0';
                        cnt %= max;
                        res += 1;
                    }

                    cnt = 1;
                }
            } else {
                cnt += 1;
            }
        }

        res += 1;
        chars[idx] = chars[chars.size()-1];
        idx += 1;
        if (cnt != 1) {
            int max = 10;
            while (max <= cnt) {
                max *= 10;
            }
            while (max >= 10) {
                max /= 10;
                chars[idx++] = cnt / max + '0';
                cnt %= max;
                res += 1;
            }
        }

        return res;
    }
};

// code_end
