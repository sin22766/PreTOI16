#include <bits/stdc++.h>

using namespace std;

int lcs(int const a[], int const b[], int n) {
    int dp[n + 10][n + 10];
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (a[i - 1] == b[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][n];
}

int main() {
    //define
    int n;
    cin >> n;
    int a[n + 10], b[n + 10];

    //input
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    cout << lcs(a, b, n);
    return 0;
}