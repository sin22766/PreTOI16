#include <bits/stdc++.h>

using namespace std;

int main() {
    //Define&Input
    int n, k;
    cin >> n >> k;
    int dp[n + 1];
    dp[0] = dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = (2 * dp[i - 1]);
        if (i > k) {
            dp[i] -= dp[i - k - 1];
        }
        dp[i] %= 2009;
        if (dp[i] < 0) dp[i] += 2009;
    }

    //Output
    cout << dp[n];
}