#include <bits/stdc++.h>
using namespace std;

class Person {
private:
    string name;
    int gradea;
    int gradeb;
    char carrer;
    char west;
    int papers;
    int award;
public:
    void set() {
        cin >> name >> gradea >> gradeb;
        cin >> carrer >> west;
        cin >> papers;
        award = money();
    }
    int money() {
        int ans = 0;
        if (gradea>80 && papers>=1)
            ans += 8000;
        if (gradea>85 && gradeb>80)
            ans += 4000;
        if (gradea>90)
            ans += 2000;
        if (gradea>85 && west=='Y')
            ans += 1000;
        if (gradeb>80 && carrer=='Y')
            ans += 850;
        return ans;
    }
    int get_award() {
        return award;
    }
    string get_name() {
        return name;
    }
};

int main() {
    int n;
    cin >> n;
    Person p[n];
    int max_award = 0;
    int idx;
    int sum_award = 0;
    for (int i=0; i<n; ++i) {
        p[i].set();
        sum_award += p[i].get_award();
        if (max_award < p[i].get_award())
            max_award = p[i].get_award(), idx = i;
    }
    cout << p[idx].get_name() << endl;
    cout << p[idx].get_award() << endl;
    cout << sum_award;

    return 0;
}
