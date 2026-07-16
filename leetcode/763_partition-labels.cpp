#include <bits/stdc++.h>
using namespace std;

// code_start

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        vector<vector<int>> hash(26, vector<int>(2, INT_MIN));
        vector<vector<int>> hash_filter;
        for (int i=0; i<s.size(); ++i) {
            if (hash[s[i] - 'a'][0] == INT_MIN) {
                hash[s[i]-'a'][0] = i;
            }
            hash[s[i]-'a'][1] = i;
        }
        for (int i=0; i<hash.size(); ++i) {
            if (hash[i][0] != INT_MIN) {
                hash_filter.push_back(hash[i]);
            }
        }
        hash = hash_filter;

        sort(hash.begin(), hash.end(),
             [](const vector<int> &a, const vector<int> &b)
             {
                 return a[0] < b[0];
             });
        int right = hash[0][1];
        int left = 0;
        for (int i=1; i<hash.size(); ++i) {
            if (hash[i][0] > right) {
                ans.push_back(right-left+1);
                left = hash[i][0];
            }
            right = max(right, hash[i][1]);
        }
        ans.push_back(right-left+1);
        return ans;
    }
};

// code_end

class Solution1 {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        int letters[26] = {0};
        for (int i=0; i<s.size(); ++i) {
            letters[s[i] - 'a'] = i;
        }
        int left=0, right=0;
        for (int i=0; i<s.size(); ++i) {
            right = max(right, letters[s[i]-'a']);
            if (i == right) {
                ans.push_back(right-left+1);
                left = right+1;
            }
        }
        return ans;
    }
};
