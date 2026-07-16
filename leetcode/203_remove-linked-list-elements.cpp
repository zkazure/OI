#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
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
  ListNode *removeElements(ListNode *head, int val) {
    ListNode dummy;
    dummy.next = head;
    ListNode *tail = &dummy;
    while (tail->next) {
      if (tail->next->val == val) {
        tail->next = tail->next->next;
      } else {
        tail = tail->next;
      }
    }
    return dummy.next;
  }
};

// code_end

class Solution1 {
public:
  ListNode *removeElements(ListNode *head, int val) {
    while (head != nullptr && head->val == val) {
      ListNode *tmp = head;
      head = tmp->next;
      delete tmp;
    }

    ListNode *cur = head;
    while (cur != nullptr && cur->next != nullptr) {
      if (cur->next->val == val) {
        ListNode *tmp = cur->next;
        cur->next = tmp->next;
        delete tmp;
      } else
        cur = cur->next;
    }

    return head;
  }
};
