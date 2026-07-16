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
    TreeNode* searchBST(TreeNode* root, int val) {
        while (root != NULL) {
            if (root->val > val) root = root->left;
            else if (root->val == val) return root;
            else root = root->right;
        }

        return root;
    }
};

// code_end

class Solution1 {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        queue<TreeNode*> que;
        if (root) que.push(root);
        while (!que.empty()) {
            int size = que.size();
            for (int i=0; i<size; ++i) {
                TreeNode *node = que.front(); que.pop();
                if (node->val == val) return node;
                
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
        }
        return NULL;
    }
};

class Solution2 {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root) return NULL;

        if (root->val > val) return searchBST(root->left, val);
        if (root->val == val) return root;
        if (root->val < val) return searchBST(root->right, val);
        
        return NULL;
    }
};
