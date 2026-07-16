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
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> que;
        if (root != nullptr) que.push(root);
        while (!que.empty()) {
            int size = que.size();
            for (int _=0; _<size; _++) {
                TreeNode *node = que.front();
                que.pop();
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
                swap(node->left, node->right);                
            }
        }
        return root;
    }
};

// code_end

class Solution1 {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root==nullptr) return nullptr;
        
        TreeNode* ans = new TreeNode(root->val);
        if (root->left) ans->right = invertTree(root->left);
        if (root->right) ans->left = invertTree(root->right);

        return ans;
    }
};

class Solution2 {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root==nullptr) return root;
        swap(root->left, root->right);

        if (root->left) invertTree(root->left);
        if (root->right) invertTree(root->right);
        
        return root;
    }
};

class Solution3 {
public:
    TreeNode* invertTree(TreeNode* root) {
        stack<TreeNode*> st;
        if (root != nullptr) st.push(root);
        while(! st.empty()) {
            TreeNode *node = st.top();
            st.pop();
            swap(node->left, node->right);
            if (node->right) st.push(node->right);
            if (node->left) st.push(node->left);
        }
        return root;
    }
};

class Solution4 {
public:
    TreeNode* invertTree(TreeNode* root) {
        stack<TreeNode*> st;
        if (root != nullptr) st.push(root);
        while(! st.empty()) {
            TreeNode *node = st.top();
            if (node == nullptr) {
                st.pop();
                node = st.top();
                st.pop();
                swap(node->left, node->right);
            } else {
                st.push(nullptr);
                if (node->right) st.push(node->right);
                if (node->left) st.push(node->left);
            }
        }
        return root;
    }
};
