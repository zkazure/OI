#include <bits/stdc++.h>
using namespace std;

// code_start

class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        unordered_set<int> visited;
        queue<int> q;
        q.push(id);
        visited.insert(id);
        while (!q.empty() && level > 0) {
            int size = q.size();

            for (int i = 0; i < size; ++i) {
                int curr = q.front(); q.pop();

                for (int fri : friends[curr]) {
                    if (!visited.count(fri)) {
                        visited.insert(fri);
                        q.push(fri);
                    }
                }

            }
            level -= 1;
        }

        unordered_map<string, int> video2freq;
        while (!q.empty()) {
            int curr = q.front(); q.pop();
            for (const string &video : watchedVideos[curr]) {
                video2freq[video] += 1;
            }
        }

        vector<pair<int, string>> freq2video;
        for (const auto &[video, freq] : video2freq) {
            freq2video.push_back({freq, video});
        }

        sort(freq2video.begin(), freq2video.end());

        vector<string> res;
        for (const auto &p : freq2video) {
            res.push_back(p.second);
        }

        return res;
    }
};

// code_end
