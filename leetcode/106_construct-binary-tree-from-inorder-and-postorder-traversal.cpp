#include <bits/stdc++.h>
#include <unordered_map>
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
    int postEnd;
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i=0; i<inorder.size(); ++i)
            idx[inorder[i]] = i;
        postEnd = postorder.size()-1;

        return helper(inorder, postorder, 0, postEnd);
    }
    
    TreeNode *helper(vector<int> &inorder, vector<int> &postorder, int left, int right) {
        if (left > right) return nullptr;
        int root_val = postorder[postEnd--];
        int val_idx = idx[root_val];
        TreeNode *root = new TreeNode(root_val);
        root->right = helper(inorder, postorder, val_idx+1, right);
        root->left = helper(inorder, postorder, left, val_idx-1);

        return root;
    }
};

// code_end

class Solution1 {
public:
    void buildChildTree(TreeNode *root,
                        vector<int> &inorder, int inl, int inr,
                        vector<int> &postorder, int pol, int por)
    {
        int idx = inl;
        for (idx=inl; idx<=inr; idx++) {
            if (inorder[idx] == root->val) break;
        }
        
        int lenl = idx - inl;
        int lenr = inr - idx;
        if (lenr < 0) return; 
        if (lenl > 0) {
            TreeNode *left = new TreeNode(postorder[pol+lenl-1]);
            root->left = left;
            buildChildTree(left, inorder, inl, idx-1, postorder, pol, pol+lenl-1);
        }
        if (lenr > 0) {
            TreeNode *right = new TreeNode(postorder[por-1]);
            root->right = right;
            buildChildTree(right, inorder, idx+1, inr, postorder, pol+lenl, por-1);
        }
        return; 
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode *root = new TreeNode(postorder[postorder.size()-1]);
        
        buildChildTree(root, inorder, 0, inorder.size()-1 , postorder, 0, postorder.size()-1);
        return root;
    }
};

class Solution2 {
public:
    TreeNode *buildTreeHelper(vector<int> &inorder, int inorderStart, int inorderEnd,
                              vector<int> &postorder, int postorderStart, int postorderEnd,
                              unordered_map<int, int> &idx)
    {
        if (inorderStart>inorderEnd || postorderStart>postorderEnd)
            return nullptr;
        
        int tree_val = postorder[postorderEnd];
        TreeNode *root = new TreeNode(tree_val);
        int root_idx = idx[tree_val];
        int left_tree_size = root_idx - inorderStart;
        int right_tree_size = inorderEnd - root_idx;

        root->left = buildTreeHelper(inorder, inorderStart, inorderStart+left_tree_size-1,
                                     postorder, postorderStart, postorderStart+left_tree_size-1,
                                     idx);
        root->right = buildTreeHelper(inorder, inorderEnd-right_tree_size+1, inorderEnd,
                                      postorder, postorderEnd-right_tree_size, postorderEnd-1,
                                      idx);

        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> idx;
        for (int i=0; i<inorder.size(); ++i)
            idx[inorder[i]] = i;

        return buildTreeHelper(inorder, 0, inorder.size()-1,
                               postorder, 0, postorder.size()-1,
                               idx);
    }

};
