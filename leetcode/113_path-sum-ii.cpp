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
    vector<vector<int>> ans;
    vector<int> path;
    void traversal(TreeNode *node, int reminder) {
        if (reminder==0 && !node->left && !node->right){
          ans.push_back(path);
          return;  
        }

        if (node->left) {
            path.push_back(node->left->val);
            traversal(node->left, reminder-node->left->val);
            path.pop_back();
        }
        if (node->right) {
            path.push_back(node->right->val);
            traversal(node->right, reminder-node->right->val);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root==nullptr) return ans;

        path.push_back(root->val);
        traversal(root, targetSum-root->val);
        return ans; 
    }
};

// code_end

class Solution1 {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        stack<TreeNode*> tree;
        stack<vector<int>> paths;
        stack<int> sums;
        if (root != nullptr) {
            tree.push(root);
            paths.push({root->val});
            sums.push(root->val);
        }
        
        while (!tree.empty()) {
            TreeNode *node = tree.top(); tree.pop();
            vector<int> path = paths.top(); paths.pop();
            int sum = sums.top(); sums.pop();
            if (!node->left && !node->right && sum==targetSum) {
                ans.push_back(path);
                continue;
            }

            vector<int> new_path;
            if (node->right) {
                tree.push(node->right);
                new_path = path;
                new_path.push_back(node->right->val);
                paths.push(new_path);
                sums.push(sum+node->right->val);
            }
            if (node->left) {
                tree.push(node->left);
                new_path = path;
                new_path.push_back(node->left->val);
                paths.push(new_path);
                sums.push(sum+node->left->val);
            }

        }

        return ans; 
    }
};
