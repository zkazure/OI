#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    int books[n];
    int cur=0, len=0;
    multiset<int> mset;
    vector<pair<int, int>> ans;
    for (int i=0; i<n; ++i) {
        cin >> books[i];
        mset.insert(books[i]);
        while (*mset.rbegin()-*mset.begin() > k) {
            mset.erase(mset.find(books[cur]));
            cur++;
        }
        if (i-cur+1 > len) {
            len = i-cur+1;
            ans.clear();
            ans.push_back(make_pair(cur+1, i+1));
        } else if (i-cur+1 == len) ans.push_back({cur+1, i+1});
    }

    cout << len << " " << ans.size() << "\n";
    for (int i=0; i<ans.size(); ++i) cout << ans[i].first << " " << ans[i].second << "\n";
    
    return 0;
}
