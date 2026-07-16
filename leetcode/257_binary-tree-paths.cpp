#include <bits/stdc++.h>
#include <string>
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        stack<TreeNode*> tree;
        stack<string> paths;
        if (root == nullptr) return ans;
        tree.push(root);
        paths.push(to_string(root->val));
        while (!tree.empty()) {
            TreeNode *node = tree.top(); tree.pop();
            string path = paths.top(); paths.pop();
            if (!node->left && !node->right) {
                ans.push_back(path);
                continue;
            }
            if (node->right) {
                tree.push(node->right);
                paths.push(path + "->"+to_string(node->right->val));
            }
            if (node->left) {
                tree.push(node->left);
                paths.push(path + "->"+to_string(node->left->val));
            }
        }
        
        return ans;
    }
};

// code_end

class Solution1 {
public:
    void traversal(TreeNode *root, string path, vector<string> &vec) {
        path += to_string(root->val);
        if (!root->left && !root->right) {
            vec.push_back(path);
            return;
        }
        if (root->left) traversal(root->left, path+"->", vec);
        if (root->right) traversal(root->right, path+"->", vec);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string path = "";
        if (root==nullptr) return ans;
        
        traversal(root, path, ans);
        return ans;
    }
};
