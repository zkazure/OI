#include <unordered_map>
#include <iostream>
#include <string>
using namespace std;

// code_start

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;
        int left = 0;
        unordered_map<char, int> last_seen;

        for (int right = left; right < s.length(); ++right) {
            char c = s[right];
            if (last_seen.find(c) != last_seen.end() && last_seen[c] >= left) {
                left = last_seen[c] + 1;
            }

            last_seen[c] = right;
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};

// code_end

int main() {
    Solution s;
    cout << s.lengthOfLongestSubstring("abcabcbb");
}

/** first solution
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() < 2) {
            return s.length();
        }

        int ans = 0;

        int left = 0, right = 1;
        while (right < s.length()) {
            for (int i = left; i < right; ++i) {
                if (s[i] == s[right]) {
                    ans = max(ans, right - left);
                    left = i + 1;
                    break;
                }
            }
            right += 1;
        }

        return max(ans, right - left);
    }
};
*/
