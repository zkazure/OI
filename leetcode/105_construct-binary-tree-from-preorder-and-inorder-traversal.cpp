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
private:
    unordered_map<int, int> idx;
    int preStart;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i=0; i<inorder.size(); ++i) {
            idx[inorder[i]] = i;
        }
        
        return helper(preorder, inorder, 0, preorder.size()-1);
    }
    TreeNode *helper(vector<int> &preorder, vector<int> &inorder, int left, int right) {
        if (left > right) return nullptr;
        
        int root_val = preorder[preStart++];
        int root_idx = idx[root_val];
        TreeNode *root = new TreeNode(root_val);

        root->left = helper(preorder, inorder, left, root_idx-1);
        root->right = helper(preorder, inorder, root_idx+1, right);

        return root;
    }
};

// code_end

