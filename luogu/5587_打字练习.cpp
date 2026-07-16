// This is a typical problem
// you are easy to omit the < in article
// I don't think this is a good problem
#include <bits/stdc++.h>
using namespace std;

int count_type(string a, string b) {
    char* arti = &a[0];
    char* type = &b[0];
    int cnt = 0;
    while (*type!='\0') {
        int more_arti = 0;
        while (*arti=='\0' && *type!='\0') {
            if (*type=='<')
                more_arti--;
            else more_arti++, type++;
            if (more_arti<0)
                arti--, more_arti=0;
        }
        while (*arti!='\0' && *type!='0') {
            if (*arti==*type) {
                cnt++;
                arti++, type++;
            } else if (*type == '<') {
                if (arti == &a[0]) 
                    type++;
                else {
                    cnt--;
                    type++, arti--;
                }
            } else arti++, type++;
        }
    }

    return cnt;
}

int main() {
    string tmp;
    vector<string> arti;
    vector<string> type;
    double time;

    getline(cin, tmp);
    while (tmp!="EOF") {
        arti.push_back(tmp);
        getline(cin, tmp);
    }
    getline(cin, tmp);
    while (tmp!="EOF") {
        type.push_back(tmp);
        getline(cin, tmp);
    }
    cin >> time;

    int cnt = 0;
    for (int i=0; i<arti.size() ; i++) {
        cnt += count_type(arti[i], type[i]);
    }

    double pwm = cnt*60/time;
    // cout << pwm;
    printf("%d", (int)round(pwm));
    // cout << round(pwm);

    return 0;
}
