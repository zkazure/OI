#include <vector>
#include <stack>
#include <string>
using namespace std;

// code_start

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int left_bracket = 0;
        vector<bool> removed(s.length(), false);

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                left_bracket += 1;
            } else if (s[i] == ')') {
                if (left_bracket == 0) {
                    removed[i] = true;
                } else {
                    left_bracket -= 1;
                }
            }
        }

        for (int i = s.length(); left_bracket > 0 && i >= 0; --i) {
            if (s[i] == '(') {
                removed[i] = true;
                left_bracket -= 1;
            }
        }

        string ans;
        for (int i = 0; i < s.length(); ++i) {
            if (removed[i]) continue;

            ans += s[i];
        }

        return ans;
    }
};

// code_end

/** solve with stack
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        if (s.length() == 0) return s;

        stack<int> st;

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                if (!st.empty() && s[st.top()] == '(') {
                    st.pop();
                } else {
                    st.push(i);
                }
            }
        }

        vector<int> v(s.length(), 0);
        while (!st.empty()) {
            v[st.top()] = -1;
            st.pop();
        }

        string ans;
        for (int i = 0; i < s.length(); ++i) {
            if (v[i] != -1) {
                ans += s[i];
            }
        }

        return ans;
    }
};
*/
