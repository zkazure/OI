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
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        int cnt=0, max_cnt=0;
        stack<TreeNode*> st;
        if (root) st.push(root);
        TreeNode *cur=NULL, *pre=NULL;
        while (!st.empty()) {
            cur = st.top(); st.pop();
            if (cur == NULL) {
                cur = st.top(); st.pop();
                if (pre == NULL) cnt = 1;
                else if (pre->val == cur->val) cnt++;
                else cnt = 1;

                if (cnt > max_cnt) {
                    max_cnt = cnt;
                    ans.clear();
                    ans.push_back(cur->val);
                } else if (cnt == max_cnt) ans.push_back(cur->val);
            
                pre = cur;
            } else {
                if (cur->right) st.push(cur->right);
                st.push(cur); st.push(NULL);
                if (cur->left) st.push(cur->left);
            }
        }
        return ans;
    }
};

// code_end

class Solution1 {
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        unordered_map<int, int> map;
        int freq = 1;
        queue<TreeNode*> que;
        if (root) que.push(root);

        while (!que.empty()) {
            int size = que.size();
            for (int i=0; i<size; ++i) {
                TreeNode *node=que.front(); que.pop();
                if (auto search=map.find(node->val); search!=map.end()) map[node->val] += 1;
                else map[node->val] = 1;
                freq = max(freq, map[node->val]);

                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
        }

        for (auto it=map.begin(); it!=map.end(); ++it) {
            if (it->second == freq) ans.push_back(it->first);
        }

        return ans;
    }
};

class Solution2 {
private:
    vector<int> ans;
    int cnt=0, max_cnt=0;
    TreeNode *pre = NULL;

    void traversal(TreeNode *cur) {
        if (cur == NULL) return ;

        traversal(cur->left);
        if (pre == NULL) cnt = 1;
        else if (pre->val == cur->val) cnt++;
        else cnt = 1;
        pre = cur;
        
        if (cnt > max_cnt) {
            max_cnt = cnt;
            ans.clear();
        }
        if (cnt == max_cnt) ans.push_back(cur->val);

        traversal(cur->right);
        return ;
    }

public:
    vector<int> findMode(TreeNode* root) {
        traversal(root);

        return ans;
    }
};
