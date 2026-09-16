
// code_start

class Solution {
private:
    struct ListNode {
        int val;
        ListNode *next;

        ListNode(int v, ListNode *n) : val(v), next(n) {}
    };
public:
    int findTheWinner(int n, int k) {
        ListNode *head = nullptr, *tail = nullptr;

        for (int i = 1; i <= k; ++i) {
            ListNode *node = new ListNode(i, nullptr);
            if (head == nullptr) {
                head = node;
                tail = node;
            } else {
                tail->next = node;
                tail = tail->next;
            }
        }

        while (head != tail) {
            tail->next = head;

            for (int i = 0; i < k; ++i) {
                head = head->next;
                tail = tail->next;
            }

            ListNode *to_delete = head;
            head = head->next;
            delete to_delete;
            tail->next = nullptr;
        }

        return head->val;
    }
};

// code_end


/** 得到地推公式
class Solution {
public:
    int findTheWinner(int n, int k) {
        // [1, 2, 3], if k = 2
        // [1, 2, 3] -> [3, 1] -> [3]
        //  0, 1, 2      0, 1      0
        // [3, 1] -> [1, 2, 3]
        int res = 0;
        for (int i = 2; i <= n; ++i) {
            res = (res + k) % n;
        }

        return res + 1;
    }
};
*/


/** 使用链表解决
class Solution {
private:
    struct Node {
        int val;
        Node *next;

        Node() : val(0), next(nullptr) {}
        Node(int v) : val(v), next(nullptr) {}
        Node(int v, Node *n) : val(v), next(n) {}
    };
public:
    int findTheWinner(int n, int k) {
        Node dummy;
        Node *head = &dummy;
        for (int i = 1; i <= n; ++i) {
            Node *node = new Node(i);
            head->next = node;
            head = node;
        }
        head->next = dummy.next;

        while (head->next != head) {
            for (int i = 0; i < k - 1; ++i) {
                head = head->next;
            }
            Node *to_delete = head->next;
            head->next = to_delete->next;

            delete to_delete;
        }

        return head->val;
    }
};
*/
