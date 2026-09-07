#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/** changing val, instead of node
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k <= 1 ||
            head == nullptr || head->next == nullptr) return head;

        stack<int> st;
        ListNode *prev = head, *node = head;
        do {
            st.push(node->val);
            node = node->next;

            if (st.size() == k) {
                node = prev;
                while (!st.empty()) {
                    node->val = st.top();
                    st.pop();
                    node = node->next;
                }
                prev = node;
            }
       } while (node != nullptr);

        return head;
    }
};
*/

/** write with stack O(k)
class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (k <= 1 ||
            head == nullptr || head->next == nullptr)
            return head;

        ListNode dummy(0, head);
        stack<ListNode *> st;
        ListNode *node = head;
        ListNode *prev = &dummy;

        do {
            st.push(node);
            node = node->next;

            if (st.size() == k) {
                prev->next = st.top();

                ListNode *curr = st.top();
                st.pop();
                while (!st.empty()) {
                    curr->next = st.top();
                    curr = st.top();
                    st.pop();
                }

                curr->next = node;
                prev = curr;
            }
        } while (node != nullptr);

        return dummy.next;
    }
};
*/

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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (k <= 1 ||
            head == nullptr || head->next == nullptr)
            return head;

        ListNode dummy(0, head);
        ListNode *prev = &dummy, *end = head;
        int cnt = 0;

        while (end != nullptr) {
            cnt += 1;
            end = end->next;

            if (cnt == k) {
                ListNode *curr = prev->next, *next = prev->next->next;

                while (next != end) {
                    ListNode *old_nn = next->next;

                    next->next = curr;
                    curr = next;
                    next = old_nn;
                }

                ListNode *old_pn = prev->next;
                prev->next = curr;
                old_pn->next = end;
                prev = old_pn;
                cnt = 0;
            }
        }

        return dummy.next;
    }
};

// code_end
