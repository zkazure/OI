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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        if (root == nullptr) return ans;

        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            double tmp = 0;
            for (int i=0; i<size; ++i) {
                TreeNode *node = que.front();
                que.pop();
                tmp += node->val;
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            ans.push_back(tmp/size);
        }

        return ans; 
    }
};

// code_end

