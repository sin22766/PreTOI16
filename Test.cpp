#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

vector<int> G[N];
int dp[N];

void dfs(int u, int p) {
    for (auto v : G[u]) {
        if (v == p) continue;
        dfs(v, u);
        dp[u] = max(dp[u], dp[v]) + 1;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) {
        dfs(i, 0);
        printf("%d\n", dp[i]);
    }

    return 0;
}