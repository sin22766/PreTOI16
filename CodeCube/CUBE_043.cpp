#include <bits/stdc++.h>

using namespace std;
using tiii = tuple<int, int, int>;
using pii = pair<int, int>;

int dp[305][2005];

int main() {
    int n, m, k;
    int s, t;
    scanf("%d%d%d", &n, &m, &k);
    scanf("%d%d", &s, &t);
    vector<tiii> graph[n + 5];
    for (int i = 0; i < m; ++i) {
        int a, b, c, w;
        scanf("%d%d%d%d", &a, &b, &c, &w);
        graph[a].emplace_back(b, c, w);
        graph[b].emplace_back(a, c, w);
        if (a == s) {
            dp[b][w] = c;
        } else if (b == s) {
            dp[a][w] = c;
        }
    }

    for (int i = 1; i <= k; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (dp[j][i]) {
                for (auto x:graph[j]) {
                    int v = get<0>(x);
                    int c = get<1>(x);
                    int w = get<2>(x);

                    if (i + w <= k) {
                        dp[v][i + w] = max(dp[v][i + w], dp[j][i] + c);
                    } else {
                        continue;
                    }
                }
            }
        }
    }
    int maxN = -1e9;
    for (int i = 1; i <= k; ++i) {
        maxN = max(maxN, dp[t][i]);
    }
    (maxN <= 0) ? cout << "Impossible" : cout << maxN;
    return 0;
}