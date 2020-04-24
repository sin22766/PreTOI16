#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int main() {
    pii mover[] = {{-1, 0},
                   {-1, 1},
                   {0,  1},
                   {1,  1},
                   {1,  0},
                   {1,  -1},
                   {0,  -1},
                   {-1, -1}};
    int m, n, sum = 0, x, y, xTemp, yTemp;
    queue<pii> q;
    cin >> m >> n;
    bool map[m][n];
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            char a;
            scanf(" %c", &a);
            map[i][j] = a == '1';
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (map[i][j]) {
                sum++;
                q.emplace(i, j);

                while (!q.empty()) {
                    x = q.front().first;
                    y = q.front().second;
                    q.pop();

                    if (!map[x][y]) {
                        continue;
                    }

                    map[x][y] = false;

                    for (auto k:mover) {
                        xTemp = x + k.first;
                        yTemp = y + k.second;
                        if (xTemp >= 0 && xTemp < m && yTemp >= 0 && yTemp < n && map[xTemp][yTemp]) {
                            q.emplace(xTemp, yTemp);
                        }
                    }
                }
            }
        }
    }
    cout << sum << "\n";
    return 0;
}