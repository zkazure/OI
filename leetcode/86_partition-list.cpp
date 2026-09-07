struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// left <, right >=

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
    ListNode* partition(ListNode* head, int x) {
        ListNode left_head, right_head;
        ListNode
            *left_end = &left_head,
            *right_end = &right_head;

        ListNode *node = head;
        while (node != nullptr) {
            ListNode *backup = node->next;

            ListNode *&abs_end =
                (node->val < x) ? left_end : right_end;

            abs_end->next = node;
            node->next = nullptr;
            abs_end = node;

            node = backup;
        }

        left_end->next = right_head.next;

        return left_head.next;
    }
};

// code_end
