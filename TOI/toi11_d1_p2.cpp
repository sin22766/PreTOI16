#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
int m, n;

int main() {
    pii mover[] = {{-1, 0},
                   {-1, 1},
                   {0,  1},
                   {1,  1},
                   {1,  0},
                   {1,  -1},
                   {0,  -1},
                   {-1, -1}};
    int sum = 0, x, y, xTemp, yTemp;
    cin >> m >> n;
    string map[m];
    set<pii> prayer;
    for (int i = 0; i < m; ++i) {
        cin >> map[i];
        for (int j = 0; j < n; ++j) {
            if (map[i][j] == '1') {
                prayer.emplace(i, j);
            }
        }
    }
    queue<pair<int, int>> q;
    while (!prayer.empty()) {
        sum++;
        q = queue<pair<int, int>>();
        q.push(*prayer.begin());

        while (!q.empty()) {
            x = q.front().first;
            y = q.front().second;
            map[x][y] = '0';
            prayer.erase({x, y});
            q.pop();

            for (auto i:mover) {
                xTemp = x + i.first;
                yTemp = y + i.second;
                if (xTemp >= 0 && xTemp < m && yTemp >= 0 && yTemp >= 0 && map[xTemp][yTemp] == '1') {
                    q.emplace(x + i.first, y + i.second);
                }
            }
        }
    }
    cout << sum << "\n";
    return 0;
}