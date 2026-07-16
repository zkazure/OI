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
    int sumOfLeftLeaves(TreeNode* root) {
        stack<TreeNode*> st;
        if (root != nullptr) st.push(root);
        int ans = 0;
        while (!st.empty()) {
            TreeNode *node = st.top(); st.pop();
            if (node == nullptr) {
                node = st.top(); st.pop();
                if (!node->left && !node->right)
                    ans += node->val;
            }
            if (node->right) st.push(node->right);
            if (node->left) {
                st.push(node->left);
                st.push(nullptr);
            }
        }

        return ans;
    }
};

// code_end

