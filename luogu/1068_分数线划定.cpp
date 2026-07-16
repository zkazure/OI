// ========== others' solution ====================
#include <bits/stdc++.h>
using namespace std;

struct Record {
    int id;
    int score;
};

bool comp(Record& a, Record& b) {
    if (a.score != b.score)
        return a.score > b.score;
    else return a.id < b.id;
}

int main() {
    int n, m;
    cin >> n >> m;
    Record a[5005];
    for (int i=1; i<=n; ++i) {
        cin >> a[i].id >> a[i].score;
    }
    sort(a+1, a+n+1, comp);
    int x = a[(int)(m*1.5)].score;
    int p;
    for (int i=n; i>0; i--) {
        if (a[i].score >= x) {
            p = i;
            break;
        }
    }
    cout << x << " " << p << endl;

    for (int i=1; i<=p; ++i) {
        cout << a[i].id << " " << a[i].score << endl;
    }

    return 0;
}

// ================ my code ======================
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> id;
    vector<int> grade;
    vector<int> idx;
    for (int i=0; i<n; i++) {
        idx.push_back(i);
        int tmp;
        cin >> tmp;
        id.push_back(tmp);
        cin >> tmp;
        grade.push_back(tmp);
    }

    for (int i=0; i<n-1; i++) {
        for (int j=i+1; j<n; j++) {
            if (id[idx[j]]<id[idx[i]])
                swap(idx[j], idx[i]);
        }
    }
    for (int i=0; i<n-1; i++) {
        for (int j=i+1; j<n; j++) {
            if (grade[idx[j]]>grade[idx[i]])
                swap(idx[j], idx[i]);
        }
    }
    m = (int) (m*1.5);
    int last = grade[idx[m-1]];
    int num = m;
    for (int i=m; i<n; i++) {
        if (grade[idx[i]]==last)
            num++;
        else break;
    }
    // int 
    // for (; i<m-1; i++) {
    //     cout << id[idx[i]] << " " << grade[idx[i]] << "\n";
    // }
    // int last = grade[idx[i]];
    // for (; i<n; ++i) {
    //     if (grade[idx[i]]!=last)
    //         break;
    //     cout << id[idx[i]] << " " << grade[idx[i]] << "\n";
    // }
    cout << last << " " << num << "\n";
    for (int i=0; i<num; i++) 
        cout << id[idx[i]] << " " << grade[idx[i]] << "\n";
    return 0;
}
