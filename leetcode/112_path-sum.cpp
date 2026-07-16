#include <bits/stdc++.h>
#include <string>
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        stack<pair<TreeNode*, int>> st;
        if (root != nullptr) st.push(pair<TreeNode*, int>(root, root->val));
        while (!st.empty()) {
            TreeNode *node = st.top().first;
            int sum = st.top().second; st.pop();
            if (!node->left && !node->right && sum==targetSum) return true;

            if (node->left) st.push(pair<TreeNode*, int>(node->left, sum+node->left->val));
            if (node->right) st.push(pair<TreeNode*, int>(node->right, sum+node->right->val));
        }
        return false;
    }
};

// code_end

class Solution1 {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        stack<TreeNode*> tree;
        stack<int> sums;
        if (root != nullptr) {
            tree.push(root);;
            sums.push(root->val);
        }
        while (!tree.empty()) {
            TreeNode *node = tree.top(); tree.pop();
            int sum = sums.top(); sums.pop();
            if (!node->left && !node->right && sum==targetSum) return true;
            
            if (node->right) {
                tree.push(node->right);
                sums.push(sum + node->right->val);
            }
            if (node->left) {
                tree.push(node->left);
                sums.push(sum + node->left->val);
            }
        }
        return false;
    }
};
