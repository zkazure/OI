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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1) return root2;
        if (!root2) return root1;

        root1->val += root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);

        return root1;
    }
};

// code_end

class Solution1 {
public:
    void helper(TreeNode *root, TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) return ;
        if ( (root1&&root1->left) || (root2&&root2->left) ) root->left = new TreeNode();
        if ( (root1&&root1->right) || (root2&&root2->right) ) root->right = new TreeNode();
        
        if (root1 && root2) {
            root->val = root1->val+root2->val;
            helper(root->left, root1->left, root2->left);
            helper(root->right, root1->right, root2->right);            
        }
        else if (root1) {
            root->val = root1->val;
            helper(root->left, root1->left, nullptr);
            helper(root->right, root1->right, nullptr);
        } 
        else {
            root->val = root2->val;
            helper(root->left, nullptr, root2->left);
            helper(root->right, nullptr, root2->right);            
        }
        
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        TreeNode *root = nullptr;
        if (root1 || root2) {
            root = new TreeNode();
            helper(root, root1, root2);
        }

        return root;
    }
};
