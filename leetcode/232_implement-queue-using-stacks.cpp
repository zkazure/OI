#include <bits/stdc++.h>
using namespace std;

// code_start

class MyQueue {
public:
    stack<int> stIn;
    stack<int> stOut;
    MyQueue() {
        
    }
    
    void push(int x) {
        while (!stOut.empty()) {
            stIn.push(stOut.top());
            stOut.pop();
        }
        stIn.push(x);
    }
    
    int pop() {
        while (!stIn.empty()) {
            stOut.push(stIn.top());
            stIn.pop();
        }

        int result = stOut.top();
        stOut.pop();
        return result;
    }
    
    int peek() {
        int result = this->pop();
        stOut.push(result);
        return result;
    }
    
    bool empty() {
        return stIn.empty() && stOut.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

// code_end

