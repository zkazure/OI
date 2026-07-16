#include <bits/stdc++.h>
using namespace std;

// code_start

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int cur = -1;
        for (int i=arr.size()-1; i>=0; --i) {
            if (arr[i] > cur) swap(arr[i], cur);
            else arr[i] = cur;
        }
        
        return std::move(arr);
    }
};

// code_end

// my solution
class Solution1 {
public:
    vector<int> replaceElements(vector<int>& arr) {
        deque<int> que;
        for (auto n : arr) {
            while (!que.empty() && que.back() < n) que.pop_back();
            que.push_back(n);
        }
        que.push_back(-1);
        for (int i=0; i<arr.size(); ++i) {
            if (arr[i]==que.front()) que.pop_front();
            arr[i] = que.front();
        }
        
        return arr;
    }
};

int main() {
    Solution s;
    vector<int> test = {17, 18, 5, 4, 6, 1};
    s.replaceElements(test);
    return 0;
}
