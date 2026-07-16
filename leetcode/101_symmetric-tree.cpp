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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        queue<TreeNode*> quel;
        quel.push(root->left);
        queue<TreeNode*> quer;
        quer.push(root->right);

        while (!quel.empty() && !quel.empty()) {
            TreeNode *a = quel.front(); quel.pop();
            TreeNode *b = quer.front(); quer.pop();
            if (!a && !b) continue;
            if (!a || !b || a->val!=b->val) return false;

            quel.push(a->right); quel.push(a->left);
            quer.push(b->left); quer.push(b->right);
        }

        return true;
    }
};

// code_end

