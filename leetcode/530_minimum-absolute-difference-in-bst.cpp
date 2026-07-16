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
    int ans = INT_MAX;
    TreeNode *pre = NULL;
    void traversal(TreeNode *cur) {
        if (!cur) return;
        traversal(cur->left);
        if (pre) ans = min(ans, cur->val - pre->val);
        pre = cur;
        traversal(cur->right);
    }

public:
    int getMinimumDifference(TreeNode* root) {
        traversal(root);
        return ans;
    }
};

// code_end

class Solution1 {
public:
    int getMinimumDifference(TreeNode* root) {
        int ans = root->val;
        if (root->right) {
            TreeNode *cur = root->right;
            int tmp;
            do {
                tmp = cur->val;
                cur = cur->left;
            } while (cur);
            ans = tmp-root->val;
            if (root->right->left || root->right->right)
                ans = min(ans, getMinimumDifference(root->right));
        }
        if (root->left) {
            TreeNode *cur = root->left;
            int tmp;
            do {
                tmp = cur->val;
                cur = cur->right;
            } while (cur);
            ans = min(ans, root->val-tmp);
            if (root->left->left || root->left->right)            
                ans = min(ans, getMinimumDifference(root->left));
        }

        return ans;
    }
};

class Solution2 {
private:
    vector<int> v;
    void traversal(TreeNode *root) {
        if (!root) return ;
        traversal(root->left);
        v.push_back(root->val);
        traversal(root->right);
    }

public:
    int getMinimumDifference(TreeNode* root) {
        v.clear();
        traversal(root);
        if (v.size() <= 1) return 0;
        
        int ans = INT_MAX;
        for (int i=1; i<v.size(); ++i) {
            ans = min(ans, v[i]-v[i-1]);
        }

        return ans;
    }
};
