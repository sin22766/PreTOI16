#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

vector<int> G[N], leaf, dp;
int maxN = 0;

void dfs(int u, int p) {
    bool endNode = true;
    for (auto v : G[u]) {
        if (v == p) continue;
        dfs(v, u);
        dp[u] = max(dp[u], dp[v]);
        endNode = false;
    }
    dp[u] += 1;
    maxN = max(maxN, dp[u]);
    if (endNode) {
        leaf.push_back(u);
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
    dp.assign(N, 0);
    dfs(1, 0);
    for (auto i:leaf) {
        dp.assign(N, 0);
        dfs(i, 0);
    }
    printf("%d\n", maxN);
    return 0;
}