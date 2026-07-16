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
private:
    bool traversal(TreeNode *root, TreeNode *node) {
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            for (int i=0; i<size; ++i) {
                TreeNode *cur = que.front(); que.pop();
                if (cur == node) return true;
                if (cur->left) que.push(cur->left);
                if (cur->right) que.push(cur->right);
            }
        }
        return false;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (traversal(p, q)) return p;
        else if (traversal(q, p)) return q;

        TreeNode *ans = NULL;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            for (int i=0; i<size; ++i) {
                TreeNode *node = que.front(); que.pop();
                if (traversal(node, p) && traversal(node, q)) ans = node;
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
        }
        return ans;
    }
};

// code_end

