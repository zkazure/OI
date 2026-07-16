#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x, next(NULL)) {}
};

// code_start

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len_a = 0, len_b = 0;
        ListNode *tmp_a = headA, *tmp_b = headB;
        while (tmp_a != NULL) {
            tmp_a = tmp_a->next;
            len_a++;
        }
        while (tmp_b != NULL) {
            tmp_b = tmp_b->next;
            len_b++;
        }
        tmp_a=headA, tmp_b=headB;

        bool flag = len_a > len_b;
        if (flag) {
            int idx = len_a - len_b;
            while (idx>0) {
                tmp_a = tmp_a->next;
                idx--;
            }
        } else {
            int idx = len_b - len_a;
            while (idx>0) {
                tmp_b = tmp_b->next;
                idx--;
            }
        }

        ListNode* ans = NULL;
        while (tmp_a != NULL) {
            if (tmp_a == tmp_b) {
                ans = tmp_a;
                break;
            }
            
            tmp_a = tmp_a->next;
            tmp_b = tmp_b->next;
        }
        
        return ans;
    }
};

// code_end

