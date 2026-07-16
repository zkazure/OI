#include <bits/stdc++.h>
using namespace std;

// code_start

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;

        unordered_map<int, vector<int>> stopToRoutes;
        for (int i = 0; i < routes.size(); ++i) {
            for (int stop : routes[i])
                stopToRoutes[stop].push_back(i);
        }

        if (stopToRoutes.find(source) == stopToRoutes.end()
            || stopToRoutes.find(target) == stopToRoutes.end())
            return -1;

        queue<pair<int, int>> q;
        q.push({source, 0});

        unordered_set<int> visitedStops;
        unordered_set<int> visitedRoutes;
        visitedStops.insert(source);

        while (!q.empty()) {
            auto [curr_stop, bus_cnt] = q.front();
            q.pop();

            for (int route_idx : stopToRoutes[curr_stop]) {
                if (visitedRoutes.count(route_idx)) continue;

                visitedRoutes.insert(route_idx);
                for (int next_stop : routes[route_idx]) {
                    if (next_stop == target) return bus_cnt + 1;

                    if (!visitedStops.count(next_stop)) {
                        visitedStops.insert(next_stop);
                        q.push({next_stop, bus_cnt + 1});
                    }
                }
            }
        }

        return -1;
    }
};

// code_end
