// 1
// 1 O(1)
// F x 1 n
#include <bits/stdc++.h>
using namespace std;

int get_comp() {
    char tmp;
    cin >> tmp >> tmp;
    cin >> tmp;
    if (tmp=='n') {
        cin >> tmp;
        int comp;
        cin >> comp;
        cin >> tmp;
        return comp;
    }
    
    cin >> tmp;
    return 0;
}

int main() {
    int t;
    cin >> t;
    for (; t>0; t--) {
        int l;
        int comp = get_comp();
        int cnt_comp = 0;
        int ans_comp = -1;
        vector<char> var;
        int loop = 0;
        bool error = false;
        for (; l>0; l--) {
            error = false;
            string tmp_str;
            getline(cin, tmp_str);
            if (error)
                continue;
            
            if (tmp_str[0]=='F') {
                loop ++;
                var.push_back(tmp_str[2]);
                for (int i=0; var.size()>1 && i<var.size()-1; i++) {
                    for (int j=i+1; j<var.size(); ++j) {
                        if (var[i]==var[j]) {
                            error = true;
                            break;
                        }
                    }
                    if (error)
                        break;
                }

                if (error)
                    continue;
                if (tmp_str[6]=='n')
                    cnt_comp++;
                else if (tmp_str[6]>=tmp_str[4])
                    cnt_comp++;

            } else if (tmp_str[0]=='E') {
                loop--;
                var.pop_back();
                if (cnt_comp<0) {
                    error = true;
                } else ans_comp = max(ans_comp, cnt_comp);
            }

        }
        if (loop>0)
            error = true;
        if (error)
            cout << "ERR" << "\n";
        else if (cnt_comp == comp)
            cout << "Yes" << "\n";
        else cout << "No" << "\n";
    }

    return 0;
}
