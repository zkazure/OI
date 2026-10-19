#include <iostream>
#include <vector>

int n, x;
std::vector<int> left, right, mid;

void sort_tree(int midl, int midr, int lefti) {
    // check
    if (midl >= midr) {
        return ;
    }

    int midm;
    for (midm = midl; midm < midr; ++midm) {
        if (left[lefti] == mid[midm]) {
            break;
        }
    }

    int left_size = midm - midl;
    sort_tree(midl, midm, lefti+1);
    sort_tree(midm+1, midr, lefti+1+left_size);
    right.push_back(left[lefti]);

    return;
}

int main() {
    while (std::cin >> n) {
        left.resize(n);
        mid.resize(n);
        right.clear();

        for (int i = 0; i < n; ++i) {
            std::cin >> left[i];
        }
        for (int i = 0; i < n; ++i) {
            std::cin >> mid[i];
        }

        sort_tree(0, n, 0);

        for (int i = 0; i < n; ++i) {
            if (i != 0) {
                std::cout << " ";
            }
            std::cout << right[i];
        }
        std::cout << "\n";
    }
    return 0;
}
