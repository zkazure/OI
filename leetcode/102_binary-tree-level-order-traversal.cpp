#include <bits/stdc++.h>
using namespace std; 

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// code_start

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;
        
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            vector<int> tmp; 
            for (int i=0; i<size; ++i) {
                TreeNode *node = que.front();
                que.pop();
                tmp.push_back(node->val);
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};

// code_end

// implement with two stack
// a bit slow
class Solution2 {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;

        stack<TreeNode*> st1;
        st1.push(root);
        while (!st1.empty()) {
            vector<int> tmp;
            stack<TreeNode*> st2; 
            while (!st1.empty()) {
                TreeNode *node = st1.top();
                st1.pop();
                st2.push(node);
                tmp.push_back(node->val);
            }
            ans.push_back(tmp);

            while (!st2.empty()) {
                TreeNode *node = st2.top();
                st2.pop();
                if (node->right) st1.push(node->right);
                if (node->left) st1.push(node->left);
            }
        }

        return ans;
    }
};
