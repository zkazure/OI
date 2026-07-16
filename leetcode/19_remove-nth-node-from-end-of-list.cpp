#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode *fast = dummy, *slow = dummy;
        while (n >= 0) {
            fast = fast->next;
            n--;
        }

        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        ListNode* tmp = slow->next;
        slow->next = tmp->next;
        delete tmp;

        ListNode* ans = dummy->next;
        delete dummy;
        
        return ans;
    }
};

// code_end

class Solution2 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int all = 0;
        ListNode* cur = head;
        while (cur != nullptr) {
            all++;
            cur = cur->next;
        }
        if (n>all)
            return head;

        int idx = all-n+1;
        ListNode* dummy = new ListNode(0, head);
        cur = dummy;
        while(idx != 1) {
            cur = cur->next;
            idx--;
        }
        
        if (cur->next == nullptr)  {
            delete cur->next;
            cur->next = nullptr;
        } else {
            ListNode* tmp = cur->next;
            cur->next = tmp->next;
            delete tmp;            
        }

        return dummy->next;
    }
};
