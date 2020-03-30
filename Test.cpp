#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int dp[n + 1];
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (i <= m) {
            dp[i] = (2 * dp[i - 1]) % 2009;
        } else {
            dp[i] = (2 * dp[i - 1] - dp[i - m - 1]) % 2009;
        }
        if (dp[i] < 0) dp[i] += 2009;
    }
    printf("%d", dp[n]);
}