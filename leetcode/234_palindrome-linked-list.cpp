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
  bool isPalindrome(ListNode *head) {
    ListNode *fast = head, *slow = head;
    ListNode *prev = nullptr, *reve = nullptr;
    while (fast && fast->next) {
      fast = fast->next->next;
      reve = slow;
      slow = slow->next;

      reve->next = prev;
      prev = reve;
    }

    if (fast) {
      slow = slow->next;
    }

    while (reve) {
      if (reve->val != slow->val)
        break;

      reve = reve->next;
      slow = slow->next;
    }

    return reve == nullptr;
  }
};

// code_end
