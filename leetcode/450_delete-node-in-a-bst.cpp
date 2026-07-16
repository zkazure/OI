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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) return root;

        TreeNode *curr = root;
        TreeNode *prev = NULL;
        while (curr != NULL) {
            if (curr->val == key) break;

            prev = curr;
            if (curr->val > key) curr = curr->left;
            else curr = curr->right;
        }
        if (curr == NULL) return root;
        
        if (prev == NULL) {
            return helper(curr);
        } else if (prev->left == curr) {
            prev->left = helper(curr);
        } else prev->right = helper(curr);

        return root;
    }

    TreeNode *helper(TreeNode *node) {
        TreeNode *res;
        if (node->right) {
            res = node->right;
            if (node->left) {
                TreeNode *curr = res;
                TreeNode *prev = res;
                while (curr != NULL) {
                    prev = curr;
                    if (curr->val > node->left->val) curr = curr->left;
                    else curr = curr->right;
                }
                if (prev->val > node->left->val) prev->left = node->left;
                else prev->right = node->left;
            }
        } else {
            res = node->left;
        }
        delete node;
        return res;
    }
};

// code_end

