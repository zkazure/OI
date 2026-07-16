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
    int _count(int n) {
        int sum = 0;
        while (n>0) {
            sum += pow(2, n);
            n--;
        }
        return sum;
    }


    int countNodes(TreeNode* root) {
        int cnt = 0;
        if (root == nullptr) return 0;

        int leftd = 0;
        TreeNode *node = root;
        while (node->left != nullptr) {
            node = node->left;
            leftd += 1;
        }
        int rightd = 0;
        node = root;
        while (node->right != nullptr) {
            node = node->right;
            rightd += 1;
        }
        if (leftd == rightd) return 1+_count(leftd);
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

// code_end

class Solution1 {
public:
    int countNodes(TreeNode* root) {
        int cnt = 0;
        stack<TreeNode*> st;
        if (root != nullptr) {
            st.push(root);
            cnt ++;
        } 
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            if (node->right) {
                st.push(node->right);
                cnt ++;
            }
            if (node->left) {
                st.push(node->left);
                cnt ++;
            }
        }

        return cnt;
    }
};

class Solution2 {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
