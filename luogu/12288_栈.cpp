#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Node {
public:
    int val;
    Node *prev;
    Node *next;

    Node() : val(0), prev(NULL), next(NULL) {}
    Node(int x) : val(x), prev(NULL), next(NULL) {}
};

class List {
public:
    Node *sentinel;
    int size;

    List() {
        sentinel = new Node();
        sentinel->next = sentinel;
        sentinel->prev = sentinel;
        size = 0;
    }
    
    void addLast(int x) {
        int idx = 0;
        Node *node = new Node(x);

        node->next = sentinel;
        node->prev = sentinel->prev;
        sentinel->prev->next = node;
        sentinel->prev = node;
        
        size += 1;
    }
    
    void addLast(Node *node) {
        node->prev = sentinel->prev;
        node->next = sentinel;
        sentinel->prev->next = node;
        sentinel->prev = node;
        size += 1;
    }

    void remove(int val) {
        Node *cur = sentinel->next;
        while (cur != sentinel) {
            if (cur->val == val) break;
            cur = cur->next;
        }

        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;

        delete cur;
        size -= 1;
    }

    void remove(Node *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
        size -= 1;
    }
};


int main() {
    int n; cin >> n;
    List *list = new List();
    unordered_map<int, Node*> map;
    int ans = 0;
    
    for (int i=0; i<n; ++i) {
        int tmp; cin >> tmp;
        if (auto sear=map.find(tmp); sear!=map.end()) {
            Node *node = map[tmp];
            Node *prev = node->prev;
            Node *next = node->next;
            if (prev!=list->sentinel && next!=list->sentinel) {
                if ( (prev->val + node->val)%2 != 0) ans -= 1;
                if ( (next->val + node->val)%2 != 0) ans -= 1;
                if ( (prev->val + next->val)%2 != 0) ans += 1;
            } else if (prev!=list->sentinel) {
                if ((prev->val+node->val)!=0)
                    ans -= 1;
            } else if (next!=list->sentinel) {
                if ((next->val+node->val)!=0)
                    ans -= 1;
            }
            list->remove(node);
            list->addLast(tmp);
        } else {
            Node *node = new Node(tmp);
            list->addLast(node);
            map[tmp] = node;
        }
        
        Node *node = map[tmp];
        if (node->prev!=list->sentinel && (node->val+node->prev->val)%2!=0 ) {
            ans += 1;
        }

        cout << ans << "\n";
    }

    return 0;
}
