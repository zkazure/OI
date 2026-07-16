#include <bits/stdc++.h>
using namespace std; 

// code_start

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i=0; i<s.size(); ++i) {
            switch (s[i]) {
            case '{': st.push('}'); break;
            case '[': st.push(']'); break;
            case '(': st.push(')'); break;
            default: {
                if (st.empty())
                    return false;
                if (s[i] == st.top())
                    st.pop();
                else return false;
            }
            }
        }
        if (st.empty())
            return true;
        return false;
    }
};

// code_end

int main() {
    return 0;
}
