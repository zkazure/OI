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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode();
        ListNode *curr = dummy;
        int total=0, carry=0;
        while (l1 || l2 || carry) {
            total = carry;
            if (l1) {
                total += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                total += l2->val;
                l2 = l2->next;
            }
            carry = total / 10;
            total %= 10;
            curr->next = new ListNode(total);
            curr = curr->next;
        }

        ListNode *res = dummy->next;
        delete dummy;
        return res;
    }
};

// code_end

class Solution1 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ans = new ListNode();
        ListNode *cur = ans;
        int next = 0;
        while (true) {
            if (l1) {
                cur->val += l1->val;
                l1 = l1->next;
            } 
            if (l2) {
                cur->val += l2->val;
                l2 = l2->next;
            }            
            if (cur->val >= 10) {
                cur->val -= 10;
                next = 1;
            } else {
                next = 0;
            }            
            if (l1!=NULL || l2!=NULL || next==1) {
                cur->next = new ListNode(next);
                next = 0;
            } else {
                break;
            }

            cur = cur->next;
        }

        return ans;
    }
};
