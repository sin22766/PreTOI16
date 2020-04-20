#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, m;
    cin >> a >> m;
    int secure[m + 1], dp[a + 1];
    fill_n(dp, a + 1, -1e9);
    for (int i = 1; i <= m; ++i) {
        cin >> secure[i];
    }
    dp[1] = secure[1];
    for (int j = 1; j <= a; ++j) {
        for (int i = j / 2; i >= 0; --i) {
            int back = j - i;
            dp[j] = max(dp[j], dp[i] + dp[back]);
        }
        if (j <= m) {
            dp[j] = max(dp[j], secure[j]);
        }
    }
    cout << dp[a];
    return 0;
}