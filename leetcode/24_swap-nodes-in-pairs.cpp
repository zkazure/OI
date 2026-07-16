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
    ListNode* swapPairs(ListNode* head) {
        if (head==nullptr)
            return nullptr;
        else if (head->next == nullptr)
            return head;

        ListNode* a = head, *b = head->next;
        head = b;
        while (true) {
            if (b->next == nullptr) {
                b->next = a;
                a->next = nullptr;
                break;
            } else if (b->next->next == nullptr){
                ListNode* c = b->next;
                a->next = c;
                b->next = a;
                break;
            }
            ListNode* c = b->next;
            a->next = c->next;
            b->next = a;
            b = a->next;
            a = c;
        }
        return head;
    }
};

// code_end

