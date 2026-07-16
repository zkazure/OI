#include <bits/stdc++.h>
using namespace std;

struct Link {
    char c;
    Link *next;
    Link(char c): c(c), next(nullptr) {}
};

int main() {

    string input;
    while (getline(cin, input)) {
        Link *dum = new Link(0);
        Link *cur = dum;
        Link *tail = dum;
        for (int i = 0; i < input.length(); ++i) {
            if (input[i] == '[') {
                cur = dum;
            }
            else if (input[i] == ']') {
                cur = tail;
            }
            else {
                Link *node = new Link(input[i]);
                node->next = cur->next;
                cur->next = node;
                cur = node;
                if (tail->next)
                    tail = tail->next;
            }
        }

        cur = dum;
        while (cur->next) {
            cout << cur->next->c;
            cur = cur->next;
        }
        cout << "\n";

        cur = dum;
        while (cur->next) {
            Link *to_delete = cur;
            cur = cur->next;
            delete to_delete;
        }
        delete cur;
    }

    return 0;
}
