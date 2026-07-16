#include <bits/stdc++.h>
using namespace std;

// code_start

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int area = 0;
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        stack<int> st;
        for (int i = 0; i < heights.size(); ++i) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                int h = heights[st.top()]; st.pop();
                if (!st.empty()) {
                    int w = i - st.top() - 1;
                    area = max(area, h * w);
                }
            }
            st.push(i);
        }
        return area;
    }
};

// code_end
