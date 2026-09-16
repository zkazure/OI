#include <bits/stdc++.h>
#include <string>
using namespace std;

// code_start

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> st;
        for (int i = 0; i < tokens.size(); ++i) {
            if (tokens[i] == "+" || tokens[i] == "-" ||
                tokens[i] == "*" || tokens[i] == "/") {
                // 第二个操作数在栈顶
                long long num2 = st.top(); st.pop();
                long long num1 = st.top(); st.pop();

                long long res;

                if (tokens[i] == "+") res = num1 + num2;
                else if (tokens[i] == "-") res = num1 - num2;
                else if (tokens[i] == "*") res = num1 * num2;
                else if (tokens[i] == "/") res = num1 / num2;

                st.push(res);
            } else {
                st.push(stoll(tokens[i]));
            }
        }
        return st.top();
    }
};

// code_end
