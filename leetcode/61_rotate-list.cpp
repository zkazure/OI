struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 先取余保证 k 小于链表长度
// 则 rotate k 表示把最后 k 个放到最前面

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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) return nullptr;

        int len = 1;
        ListNode *end = head;
        while (end->next != nullptr) {
            len += 1;
            end = end->next;
        }

        k %= len;
        if (k == 0) return head;

        ListNode *new_end = head;
        int cnt = len - k;
        while (cnt > 1) {
            new_end = new_end->next;

            cnt -= 1;
        }

        ListNode *new_head = new_end->next;
        new_end->next = nullptr;
        end->next = head;
        return new_head;
    }
};

// code_end
