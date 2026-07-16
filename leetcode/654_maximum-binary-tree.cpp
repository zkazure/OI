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
    TreeNode *helper(vector<int> &nums, int left, int right) {
        if (left > right) return nullptr;
        int m=nums[left];
        for (int i=left+1; i<=right; ++i) m = max(m, nums[i]);
        int mp = idx[m];
        TreeNode *root = new TreeNode(m);
        root->left = helper(nums, left, mp-1);
        root->right = helper(nums, mp+1, right);
        
        return root;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        for (int i=0; i<nums.size(); ++i) idx[nums[i]] = i;

        return helper(nums, 0, nums.size()-1);
    }
};

// code_end

