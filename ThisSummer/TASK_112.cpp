#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf(" %d", &n);
    long long secure[n], dp[n], result = -1e10;
    for (int i = 0; i < n; ++i) {
        scanf(" %lld", &secure[i]);
        dp[i] = secure[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (secure[j] < secure[i]) {
                dp[i] = max(dp[i], secure[i] + dp[j]);
            }
        }
        result = max(result, dp[i]);
    }
    cout << result;
    return 0;
}