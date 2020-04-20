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
    string temp;
    cin >> m >> n;
    set<pii> prayer;
    bool checker[m][n];
    for (int i = 0; i < m; ++i) {
        cin >> temp;
        for (int j = 0; j < n; ++j) {
            if (temp[j] == '1') {
                prayer.emplace(i, j);
                checker[i][j] = true;
            } else {
                checker[i][j] = false;
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
            checker[x][y] = false;
            prayer.erase({x, y});
            q.pop();

            for (auto i:mover) {
                xTemp = x + i.first;
                yTemp = y + i.second;
                if (xTemp >= 0 && xTemp < m && yTemp >= 0 && yTemp < n && checker[xTemp][yTemp]) {
                    q.emplace(xTemp, yTemp);
                }
            }
        }
    }
    cout << sum << "\n";
    return 0;
}