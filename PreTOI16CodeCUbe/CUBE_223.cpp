#include <bits/stdc++.h>

using namespace std;

int main() {
    pair<int, int> checker[3] = {{0,  -1},
                                 {-1, -1},
                                 {-1, 0}};
    int n, m, t, sum = 0, tempN, minN;
    scanf(" %d %d", &n, &m);
    char temp[m + 10];
    t = min(n, m);
    vector<vector<int>> pic(n + 10, vector<int>(m + 10, 0)), picT;
    for (int i = 0; i <= n; ++i) {
        if (i != 0) {
            scanf(" %s", &temp);
        }
        for (int j = 0; j <= m; ++j) {
            if (!i || !j) {
                pic[i][j] = 0;
            } else {
                pic[i][j] = temp[j] - '0';
                sum += pic[i][j];
            }
        }
    }
    cout << sum << "\n";
    for (int T = 1; T < t; ++T) {
        sum = 0;
        minN = 1e9;
        for (int i = 1; i < n - T + 1; ++i) {
            for (int j = 1; j < m - T + 1; ++j) {
                if (pic[i][j]) {
                    tempN = 1e9;
                    for (auto k:checker) {
                        tempN = min(tempN, pic[i + k.first][j + k.second]);
                    }
                    if (tempN + 1)
                }
            }
        }
        cout << sum << "\n";
    }
    return 0;
}