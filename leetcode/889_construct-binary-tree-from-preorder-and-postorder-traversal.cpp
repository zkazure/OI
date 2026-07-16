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
    int preStart = 0;

    TreeNode *helper(vector<int> &preorder, vector<int> &postorder, int left, int right) {
        if (left > right) return nullptr;
        
        int root_val = preorder[preStart++];
        int left = 
        TreeNode *root = new TreeNode(root_val);
        root->left = helper(preorder, postorder, )
    }
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        for (int i=0; i<postorder.size(); ++i) idx[postorder[i]] = i;

        return helper(preorder, postorder, 0, postorder.size()-1);
    }
};

// code_end

