#include <bits/stdc++.h>

using namespace std;

int n, p;

int main() {
    scanf(" %d %d", &n, &p);
    int energy[n];
    long long dp[p + 1][n + 1];
    for (int i = 0; i < n; ++i) {
        scanf(" %d", &energy[i]);
    }
    for (int i = 0; i <= p; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (!i || !j) {
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = dp[i][j - 1];
            if (i == energy[j - 1]) {
                dp[i][j]++;
            } else if (i > energy[j - 1]) {
                dp[i][j] += dp[i - energy[j - 1]][j];
            }
            dp[i][j] %= (long long) 1e9 + 7;
        }
    }
    cout << dp[p][n];
    return 0;
}