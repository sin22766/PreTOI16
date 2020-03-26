#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, temp, lane, speed, maxLap = 0, curr_laps;
    cin >> n >> m;
    vector<pair<int, int>> t_lane[m];
    vector<pair<int, pair<int, int>>> lap[n];
    for (int i = 0; i < n; ++i) {
        cin >> temp >> lane >> speed;
        t_lane[lane - 1].emplace_back(speed, temp);
        curr_laps = t_lane[lane - 1].size() - 1;
        if (curr_laps > maxLap) {
            maxLap = curr_laps;
        }
        lap[curr_laps].push_back({speed, {lane, temp}});
    }
    for (int j = 0; j < maxLap + 1; ++j) {
        int maxS = 0, minLane, racer;
        for (auto i:lap[j]) {
            if (i.first > maxS) {
                maxS = i.first;
                minLane = i.second.first;
                racer = i.second.second;
            } else if (i.first == maxS && i.second.first < minLane) {
                minLane = i.second.first;
                racer = i.second.second;
            }
        }
        cout << racer << "\n";
    }
    return 0;
}