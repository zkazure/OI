#include <vector>
#include <stack>
#include <string>
using namespace std;

// code_start

class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> dp(s.length(), 0);
        int ans = 0;

        // dp[i] 是以 *s[i]* 为结尾的最长子序列的长度
        if (s[0] == '(' && s[1] == ')') {
            dp[1] = 2;
            ans = 2;
        }


        for (int i = 2; i < s.length(); i += 1) {
            // 从左到右，) 才会触发匹配
            if (s[i] == ')') {
                if (s[i-1] == '(') {
                    dp[i] = dp[i-2] + 2;
                } else {
                    int j = i - dp[i-1] - 1; // 中间未匹配的 ( 的索引
                    if (j >= 0 && s[j] == '(') {
                        dp[i] = dp[i - 1] + 2; // ()(() ) 后半部分

                        if (j >= 1) {
                            dp[i] += dp[j - 1]; // ()(() ) 前半部分
                        }
                    }
                }
            }

            ans = max(ans, dp[i]);
        }

        return ans;
    }
};

// code_end

/** 双向扫描
class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        int left = 0, right = 0;

        // 从左到右扫描，优先消除右括号
        for (int i = 0; i < s.length(); i += 1) {
            if (s[i] == '(') {
                left += 1;
            } else {
                right += 1;
            }

            if (right > left) {
                right = 0, left = 0; // ) 多了，无法匹配，重新计数
            } else if (left == right) {    // 只有相等的时候应该计数, ()(()
                ans = max(ans, 2 * right); // 我们允许左括号多，等待匹配
            }
        }

        // 从右到左匹配，因为如果 (() 在从左到右扫描的时候是无法触发计数的
        left = 0, right = 0;
        for (int i = s.length() - 1; i >= 0; i -= 1) {
            if (s[i] == '(') {
                left += 1;
            } else {
                right += 1;
            }

            if (left > right) {
                left = 0, right = 0;
            } else if (left == right) {
                ans = max(ans, 2 * left);
            }
        }

        return ans;
    }
};
*/


/** 简单的栈匹配
class Solution {
public:
    int longestValidParentheses(string s) {
        // 假设之前的字符串完美匹配，或者从第一个无法匹配的字符 ) 开始
        stack<int> st;
        st.push(-1);

        int maxn = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();         // 不管如何先匹配
                if (st.empty()) { // 如果匹配的是一个未匹配的右括号
                    st.push(i);
                } else {        // 如果刚刚匹配的是 (
                    maxn = max(maxn, i - st.top());
                }
            }
        }

        return maxn;
    }
};
*/
