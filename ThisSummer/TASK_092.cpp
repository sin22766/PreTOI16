#include <bits/stdc++.h>

using namespace std;

int dp[1010][1010], arr[1010][1010];

int Solver(int n, int m) {
    int minN = INT_MAX;
    for (int i = n; i > 0; --i) {
        for (int j = 1; j <= m; ++j) {
            if (i == n) {
                dp[i][j] = arr[i][j];
            } else {
                dp[i][j] = min(min(dp[i + 1][j], dp[i + 1][j - 1]), dp[i + 1][j + 1]) + arr[i][j];
            }
        }
    }
    for (int k = 1; k <= m; ++k) {
        if (dp[1][k] < minN) {
            minN = dp[1][k];
        }
    }
    return minN;
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
            dp[i][j] = INT_MAX;
        }
    }
    int result = Solver(n, m);
    if (result < 5000 + n * 500) {
        cout << result;
    } else {
        cout << "-1";
    }
    return 0;
}