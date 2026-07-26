#include <vector>
#include <queue>
#include <string>
#include <iostream>
using namespace std;

struct Node {
    bool has_value;
    int value;
    Node *left;
    Node *right;
    Node() : has_value(false), value(0), left(nullptr), right(nullptr) {}
};

Node *root = nullptr;
bool failed = false;

void tree_clean(Node *root) {
    if (root == nullptr) return ;

    tree_clean(root->left);
    tree_clean(root->right);
    delete root;

    failed = false;
}

void node_add(int v, const string &path) {
    if (root == nullptr) root = new Node();
    Node *curr = root;

    for (char c : path) {
        if (c == 'L') {
            if (curr->left == nullptr)
                curr->left = new Node();
            curr = curr->left;
        } else if (c == 'R') {
            if (curr->right == nullptr)
                curr->right = new Node();
            curr = curr->right;
        }
    }

    if (curr->has_value == true) failed = true;

    curr->value = v;
    curr->has_value = true;
}

void tree_print() {
    if (failed || !root) {
        cout << "not complete\n";
        return;
    }

    queue<Node*> q;
    vector<int> ans;
    if (root) q.push(root);

    while (!q.empty()) {
        Node *curr = q.front(); q.pop();

        if (!curr->has_value) {
            cout << "not complete\n";
            return;
        }

        ans.push_back(curr->value);

        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }


    for (const int v : ans) {
        cout << v << " ";
    }
    cout << "\n";
}

int main() {
    string input;
    while (cin >> input) {
        if (input == "()") {
            // print
            tree_print();
            tree_clean(root);
            root = nullptr;

            continue;
        }

        int comma_pos = input.find(',');
        int val = stoi(input.substr(1, comma_pos-1));
        string path = input.substr(comma_pos+1, input.length()-comma_pos-2);

        node_add(val, path);
    }

    return 0;
}
