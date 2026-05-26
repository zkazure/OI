#include <bits/stdc++.h>
using namespace std;

// code_start

// 不是普通的遍历，有一定的规则：
// ( first
// 或者可以看成是 0 1 排列？000111 001011 001101 010011 010101
// 或者不一次性全部生成，而是生成一部分？不行，不知道某一项需要多少的（
// 这居然是一个深搜的题目 too crazy
class Solution {
public:
    vector<string> answer;
    void dfs(int n, int l, int r, string v) {
        if (r == n) {
            answer.push_back(v);
            return;
        }
        if (l < n) {
            dfs(n, l+1, r, v+"(");
        }
        if (r < l) {
            dfs(n, l, r+1, v+")");
        }

    }
    vector<string> generateParenthesis(int n) {
        dfs(n, 0, 0, "");
        return answer;
    }
};

// code_end
