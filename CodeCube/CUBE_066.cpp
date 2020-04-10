#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, pair<int, int>>;

pair<int, int> Checker[4] = {{-1, 0},
                             {0,  1},
                             {1,  0},
                             {0,  -1}}; // N,E,S,W

int main() {
    //initialize
    int n, m, alive = 0;
    queue<pii> infected;

    cin >> n >> m;
    int village[n + 10][m + 10];

    //Input
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf(" %d", &village[i][j]);
            if (village[i][j] == 0) {
                infected.push({1, {i, j}});
            } else {
                alive++;
            }
        }
    }

    //Process
    int day, row, col, r, c;
    while (!infected.empty()) {
        day = infected.front().first;
        row = infected.front().second.first;
        col = infected.front().second.second;
        infected.pop();
        if (row < 0 || row >= n || col < 0 || col >= m) {
            continue;
        }
        for (auto i:Checker) {
            r = row + i.first;
            c = col + i.second;
            if (r >= 0 && r < n && c >= 0 && c < m) {
                if (village[r][c] > day) {
                    village[r][c] = 0;
                    infected.push({day + 1, {r, c}});
                    alive--;
                }
            }
        }
    }
    cout << alive;
    return 0;
}