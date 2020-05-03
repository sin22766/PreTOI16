#include <bits/stdc++.h>

using namespace std;

int main() {
    int T, n, S;
    scanf(" %d", &T);
    for (int t = 0; t < T; ++t) {
        scanf(" %d %d", &n, &S);
        int arr[n];
        for (int i = 0; i < n; ++i) {
            scanf(" %d", &arr[i]);
        }
        if (S < 0 || S > 10000) {
            cout << "No\n";
            continue;
        }
        bool dp[n + 5][S + 5];
        for (int i = 0; i < n; ++i) {
            dp[i][0] = true;
        }
        for (int i = 1; i <= S; ++i) {
            dp[0][i] = false;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= S; ++j) {
                if (j < arr[i - 1]) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
                }
            }
        }
        if (dp[n][S]) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}