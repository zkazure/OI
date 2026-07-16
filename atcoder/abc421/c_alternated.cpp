#include <bits/stdc++.h>
using namespace std;

int swap_steps(string& s, char* lp, char* rp, char a, char b) {
    if (*lp == '\0')
        return 0;

    bool flag = false;
    while(*lp != '\0') {
        if (*lp == a && *lp == *(lp+1)) {
            flag = true;
            lp++;
            break;
        }
        lp++;
    }
    if (!flag)
        return 0;
    while (*rp!='\0') {
        if (*rp == b) {
            char tmp = *lp;
            *lp = *rp;
            *rp = *lp;
            break;
        }
        rp++;
    }

    if (*rp != '\0')
        return (rp-lp) + swap_steps(s, lp, (rp++), a, b);
    
    return 0;
}

int main() {
    int n; string s;
    cin >> n >> s;
    char* lp = &s[0];
    char* rp = lp;

    int Astep = swap_steps(s, lp, rp, 'A', 'B');
    int Bstep = swap_steps(s, lp, rp, 'B', 'A');

    if (Astep > Bstep)
        printf("%d", Bstep);
    else printf("%d", Astep);

    return 0;
}
