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

// iteration with tag
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr)
            return ans;

        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode *cur = st.top();
            if (cur != nullptr) {
                st.pop();
                if (cur->right) st.push(cur->right);
                if (cur->left) st.push(cur->left);
                st.push(cur); st.push(nullptr);
            } else {
                st.pop();
                cur = st.top();
                st.pop();
                ans.push_back(cur->val);
            }
        }
        return ans;
    }
};

// code_end


// iteration version
class Solution3 {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        if (root == nullptr)
            return ans;
        st.push(root);
        while (!st.empty()) {
            TreeNode *cur = st.top();
            st.pop();
            ans.push_back(cur->val);
            if (cur->right)
                st.push(cur->right);
            if (cur->left)
                st.push(cur->left);
        }
        
        return ans;
    }
};

// recursion version
class Solution2 {
public:
    void traversal(TreeNode *cur, vector<int> &vec) {
        if (cur == nullptr)
            return;
        vec.push_back(cur->val);
        traversal(cur->left, vec);
        traversal(cur->right, vec);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        traversal(root, ans);
        
        return ans;
    }
};
