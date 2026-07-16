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
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode dummy;
    ListNode *tail = &dummy;

    while (list1 && list2) {
      if (list1->val < list2->val) {
        tail->next = list1;
        list1 = list1->next;
      } else {
        tail->next = list2;
        list2 = list2->next;
      }
      tail = tail->next;
    }

    tail->next = list1 ? list1 : list2;

    return dummy.next;
  }
};

// code_end

class Solution1 {
public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    if (list1 == nullptr && list2 == nullptr)
      return nullptr;
    if (list1 == nullptr)
      return list2;
    if (list2 == nullptr)
      return list1;

    ListNode dummy;
    dummy.next = list1;
    ListNode *a = &dummy, *b = list2;

    while (b) {
      if (a->next && b->val >= a->next->val) {
        a = a->next;
      } else {
        ListNode *node = b->next;
        b->next = a->next;
        a->next = b;
        b = node;
      }
    }

    return dummy.next;
  }
};
