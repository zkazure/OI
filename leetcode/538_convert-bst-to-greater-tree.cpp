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
    TreeNode* convertBST(TreeNode* root) {
        stack<TreeNode *> st;
        if (root) st.push(root);
        TreeNode *prev = new TreeNode(0);
        while (!st.empty()) {
            TreeNode *curr = st.top(); st.pop();
            if (curr == NULL) {
                curr = st.top(); st.pop();
                curr->val += prev->val;
                prev = curr;
            } else {
                if (curr->left) st.push(curr->left);
                st.push(curr); st.push(NULL);
                if (curr->right) st.push(curr->right);
            }
        }

        return root;
    }
};

// code_end

