#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    scanf(" %d %d", &n, &m);
    int map[n + 2][m + 2], dp[n + 2][m + 2];
    for (int i = 0; i <= n + 1; ++i) {
        for (int j = 0; j <= m + 1; ++j) {
            if (i != 0 && j != 0 && i != n + 1 && j != m + 1) {
                scanf(" %d", &map[i][j]);
            }
            dp[i][j] = 1e9;
        }
    }

    dp[1][1] = map[1][1];
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            dp[i][j] = min(dp[i][j], min(dp[i - 1][j], dp[i][j - 1]) + map[i][j]);
        }
    }
    cout << dp[n][m];
    return 0;
}