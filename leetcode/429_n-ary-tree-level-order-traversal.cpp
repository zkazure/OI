#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node (int _val, vector<Node*> _children) {
        val = _val;
        children =  _children;
    }
};

// code_start

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;

        queue<Node*> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();

            vector<int> vec;
            for (int i=0; i<size; ++i) {
                Node *node = que.front();
                que.pop();
                for (Node *item : node->children) {
                    if (item) que.push(item);
                }
                vec.push_back(node->val);
            }
            ans.push_back(vec);
        }
        
        return ans; 
    }
};

// code_end

