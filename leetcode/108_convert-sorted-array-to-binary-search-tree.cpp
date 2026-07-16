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
    TreeNode* sortedArrayToBST(vector<int>& nums) {

        TreeNode *root = new TreeNode(0);
        queue<TreeNode *> nodeQue; nodeQue.push(root);
        
        queue<int> leftQue; leftQue.push(0);
        queue<int> rightQue; rightQue.push(nums.size()-1);

        while (!nodeQue.empty()) {
            TreeNode *curr = nodeQue.front(); nodeQue.pop();
            int left = leftQue.front(); leftQue.pop();
            int right = rightQue.front(); rightQue.pop();

            int mid = (left+right+1) /2;
            curr->val = nums[mid];
            
            if (left < mid) {
                TreeNode *item = new TreeNode(0);
                curr->left = item;
                nodeQue.push(item);
                leftQue.push(left);
                rightQue.push(mid-1);
            }

            if (right > mid) {
                TreeNode *item = new TreeNode(0);
                curr->right = item;
                nodeQue.push(item);
                leftQue.push(mid+1);
                rightQue.push(right);
            }
        }
        return root;
    }
};

// code_end


class Solution1 {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0) return NULL;

        return helper(nums, 0, nums.size()-1);
    }
    
    TreeNode *helper(vector<int> &nums, int a, int b) {
        if (a > b) return NULL;
        int mid = (a+b+1)/2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = helper(nums, a, mid-1);
        root->right = helper(nums, mid+1, b);
        return root;
    }
};
