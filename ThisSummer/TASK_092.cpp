#include <bits/stdc++.h>

using namespace std;

int dp[1010][1010], arr[1010][1010];

int Solver(int n, int m) {
    int maxN = INT_MIN;
    for (int i = n; i > 0; --i) {
        for (int j = 1; j <= m; ++j) {
            if (i == n) {
                dp[i][j] = 5000 - arr[i][j];
            } else {
                if (dp[i + 1][j] > arr[i][j] || dp[i + 1][j - 1] > arr[i][j] || dp[i + 1][j + 1] > arr[i][j]) {
                    dp[i][j] = max(max(dp[i + 1][j], dp[i + 1][j - 1]), dp[i + 1][j + 1]) - arr[i][j];
                } else {
                    return -1;
                }
            }
            if (dp[i][j] > 0) {
                dp[i][j] += 500;
            }
        }
    }
    for (int k = 1; k <= m; ++k) {
        if (dp[1][k] > maxN) {
            maxN = dp[1][k];
        }
    }
    return maxN;
}

int main() {
    int n, m, temp;
    cin >> n >> m;
    for (int i = 0; i <= n + 1; ++i) {
        for (int j = 0; j <= m + 1; ++j) {
            if (i > 0 && j > 0 && i <= n && j <= m) {
                cin >> temp;
                arr[i][j] = temp;
            }
            dp[i][j] = INT_MIN;
        }
    }
    int result = Solver(n, m);
    if (result > 0) {
        cout << (5000 + 500 * n) - result;
    } else {
        cout << -1;
    }
    return 0;
}