#include <iostream>
#include <locale>
#include <stack>
#include <string>
using namespace std;

// code_start

class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> symbols;

        for (char sym : expression) {
            if (sym == ',' || sym == '(') {
                continue;
            } else if (sym != ')') {
                symbols.push(sym);
                continue;
            }

            bool hasTrue = false, hasFalse = false;
            while (symbols.top() == 't' || symbols.top() == 'f') {
                char val = symbols.top();
                symbols.pop();

                if (val == 't') hasTrue = true;
                if (val == 'f') hasFalse = true;
            }

            char op = symbols.top();
            symbols.pop();
            if (op == '!') {
                symbols.push(hasTrue ? 'f' : 't');
            } else if (op == '&') {
                symbols.push(hasFalse ? 'f' : 't');
            } else {
                symbols.push(hasTrue ? 't' : 'f');
            }
        }

        return symbols.top() == 't';
    }
};

// code_end

/** first version
class Solution {
private:
    stack<char> symbols;
    stack<char> operators;

void logic_not() {
    char val = symbols.top();
    symbols.pop();
    symbols.pop();          // pop out '('

    if (val == 'f') {
        symbols.push('t');
    } else {
        symbols.push('f');
    }
    return ;
}

void logic_and() {
    while (symbols.top() == 't' ) {
        symbols.pop();
    }

    if (symbols.top() == 'f') {
        while (symbols.top() != '(') {
            symbols.pop();
        }
        symbols.pop();
        symbols.push('f');
    } else {
        symbols.pop();
        symbols.push('t');
    }
}

void logic_or() {
    while (symbols.top() == 'f' ) {
        symbols.pop();
    }

    if (symbols.top() == 't') {
        while (symbols.top() != '(') {
            symbols.pop();
        }
        symbols.pop();
        symbols.push('t');
    } else {
        symbols.pop();
        symbols.push('f');
    }
}

public:
    bool parseBoolExpr(string expression) {
        for (int i = 0; i < expression.length(); ++i) {
            char &sym = expression[i];

            if (sym == ',') {
                continue;
            } else if (sym == ')') {
                char op = operators.top();
                operators.pop();

                char val;
                if (op == '!') {
                    logic_not();
                } else if (op == '&') {
                    logic_and();
                } else if (op == '|') {
                    logic_or();
                }

            } else if (sym == '!' || sym == '&' || sym == '|') {
                operators.push(sym);
            } else {
                symbols.push(sym);
            }
        }

        return symbols.top() == 't';
    }
};
 */

int main() {
    string expression;
    expression = "&(|(f))";
    // cin >> expression;


    Solution s;
    cout << s.parseBoolExpr(expression);
}
