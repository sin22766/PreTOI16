#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf(" %d", &n);
    int memory[n];
    long long dp[n];
    for (int i = 0; i < n; ++i) {
        scanf(" %d", &memory[i]);
    }
    dp[0] = max(memory[0], 0);
    if (n > 1) {
        dp[1] = max((long long) memory[1], dp[0]);
    }
    for (int i = 2; i < n; ++i) {
        dp[i] = max(memory[i] + dp[i - 2], dp[i - 1]);
    }
    cout << max(dp[n - 1], (long long) 0);
    return 0;
}