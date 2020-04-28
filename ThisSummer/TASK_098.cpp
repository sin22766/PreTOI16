#include <bits/stdc++.h>

using namespace std;

int main() {
    pair<int, int> checker[3] = {{0,  -1},
                                 {-1, -1},
                                 {-1, 0}};
    int n, m, result = 0, temp;
    scanf(" %d %d", &n, &m);
    int map[n + 1][m + 1];
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if (i && j) {
                scanf(" %d", &map[i][j]);
            } else {
                map[i][j] = 0;
                continue;
            }
            if (map[i][j]) {
                temp = 1e9;
                for (auto k:checker) {
                    temp = min(temp, map[i + k.first][j + k.second]);
                }
                map[i][j] = temp + 1;
            }
            result = max(result, map[i][j]);
        }
    }
    cout << result << "\n";
    return 0;
}

