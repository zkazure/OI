#include <stack>
#include <cctype>
#include <iostream>
#include <string>
using namespace std;

// code_start

// 双指针是很好的解决方案
class Solution {
public:
    string format_string(string s) {

        string new_s;
        for (int i = 0; i < s.length(); ++i) {
            if (isalpha(s[i])) {
                char temp = s[i];
                if (isupper(s[i])) {
                    temp = temp - 'A' + 'a';
                }

                new_s += temp;
            } else if (isdigit(s[i])) {
                new_s += s[i];
            }
        }

        return new_s;
    }
public:
    bool isPalindrome(string s) {
        stack<char> st;
        s = format_string(s);
        for (int i = 0; i < s.length() / 2; ++i) {
            st.push(s[i]);
        }

        for (int i = (s.length()+1) / 2; i < s.length(); ++i) {
            if (st.top() != s[i]) {
                return false;
            }
            st.pop();
        }

        return true;
    }
};

// code_end

int main() {
    string test = "A man, a plan, a canal: Panama";
    Solution s;
    cout << s.isPalindrome(test);
}
