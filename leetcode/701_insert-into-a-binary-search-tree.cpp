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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == NULL) {
            root = new TreeNode(val);
            return root;
        }
        
        TreeNode *curr = root;
        TreeNode *prev = root;
        while (curr != NULL) {
            if (curr->val > val) {
                prev = curr;
                curr = curr->left;
            } else {
                prev = curr;
                curr = curr->right;
            }
        }
        TreeNode *item = new TreeNode(val);
        if (prev->val > val) prev->left = item;
        else prev->right = item;
        
        return root;
    }
};

// code_end

