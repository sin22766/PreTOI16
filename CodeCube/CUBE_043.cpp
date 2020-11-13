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
    }

    queue<pii> q;
    q.emplace(s, 0);
    while (!q.empty()) {
        int u = q.front().first;
        int time = q.front().second;
        q.pop();

        for (auto i:graph[u]) {
            int v = get<0>(i);
            int c = get<1>(i);
            int w = get<2>(i);

            if (time + w <= k) {
                dp[v][time + w] = max(dp[v][time + w], dp[u][time] + c);
                q.emplace(v, time + w);
            }
        }
    }
    int maxN = -1e9;
    for (int i = 1; i <= k; ++i) {
        if (dp[t][i] > 0) {
            maxN = max(maxN, dp[t][i]);
        }
    }

    if (maxN <= 0) {
        cout << "Impossible";
    } else {
        cout << maxN;
    }
    return 0;
}