#include <stack>
#include <string>
using namespace std;

// code_start

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.length(); i += 1) {
            bool should_pushed = true;

            if (!st.empty()) {
                switch (st.top()) {
                case '(': {
                    if (s[i] == ')') should_pushed = false;
                    break;
                }
                case '[': {
                    if (s[i] == ']') should_pushed = false;
                    break;
                }
                case '{': {
                    if (s[i] == '}') should_pushed = false;
                    break;
                }
                }
            }

            if (should_pushed) {
                st.push(s[i]);
            } else {
                st.pop();
            }
        }

        return st.empty();
    }
};

// code_end
