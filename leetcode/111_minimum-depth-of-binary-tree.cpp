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
    int minDepth(TreeNode* root) {
        int ans = 0;
        queue<TreeNode*> que;
        if (root != NULL) que.push(root);

        while (!que.empty()) {
            int size = que.size();
            ans++;
            for (int i=0; i<size; ++i) {
                TreeNode *node = que.front();
                que.pop();
                if (!node->left && !node->right)
                    return ans;
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
        }

        return ans;
    }
};

// code_end

