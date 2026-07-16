#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// code_start

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *a, *b;
        if (p->val > q->val) a=p, b=q;
        else a=q, b=p;
        
        TreeNode *curr = root;
        TreeNode *flag;
        while (true) {
            if (curr->val > a->val) curr = curr->left;
            else if (curr->val < b->val) curr = curr->right;
            else return curr;
        }

        return NULL;
    }
};

// code_end
