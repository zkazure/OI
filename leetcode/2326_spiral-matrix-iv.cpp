#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// code_start

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  vector<vector<int>> spiralMatrix(int m, int n, ListNode *head) {
    int top = 0, bottom = m - 1;
    int left = 0, right = n - 1;
    ListNode *node = head;
    vector<vector<int>> ans(m, vector<int>(n, -1));

    while (top <= bottom && left <= right) {
      if (node == nullptr)
        break;

      for (int i = left; i <= right; i++) {
        if (node == nullptr)
          break;
        ans[top][i] = node->val;
        node = node->next;
      }
      top++;
      for (int i = top; i <= bottom; i++) {
        if (node == nullptr)
          break;
        ans[i][right] = node->val;
        node = node->next;
      }
      right--;
      for (int i = right; top <= bottom && i >= left; i--) {
        if (node == nullptr)
          break;
        ans[bottom][i] = node->val;
        node = node->next;
      }
      bottom--;
      for (int i = bottom; left <= right && i >= top; i--) {
        if (node == nullptr)
          break;
        ans[i][left] = node->val;
        node = node->next;
      }
      left++;
    }

    return ans;
  }
};

// code_end
