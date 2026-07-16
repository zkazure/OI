#include <bits/stdc++.h>
using namespace std;

// code_start

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res(nums.size(), -1);
        stack<int> st;
        int len = nums.size();
        for (int i = 0; i < 2 * len; ++i) {
            // 之所以可以直接遍历两遍，是因为如果右侧没有匹配，第二遍的时候也不
            // 可能匹配上了。
            while (!st.empty() && nums[i % len] > nums[st.top()]) {
                res[st.top()] = nums[i % len];
                st.pop();
            }
            st.push(i % len);
        }

        return res;
    }
};

// code_end
