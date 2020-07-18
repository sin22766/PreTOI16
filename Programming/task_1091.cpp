#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, maxN = 1;
    scanf("%d", &n);

    vector<int> graph[n + 1], dp(n + 1, 1);

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        graph[min(u, v)].push_back(max(u, v));
    }

    for (int u = 1; u <= n; ++u) {
        for (int v:graph[u]) {
            dp[v] = max(dp[u] + 1, dp[v]);
        }
        maxN = max(maxN, dp[u]);
    }

    printf("%d\n", maxN);
    return 0;
}