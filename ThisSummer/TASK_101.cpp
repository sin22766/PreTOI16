#include<bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int path[1005][1005];
int dp[1005][1005];

int main() {
    pii mover[4] = {{1,  0},
                    {0,  1},
                    {0,  -1},
                    {-1, 0}};
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            scanf("%d", &path[i][j]);
        }
    }

    int result = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (dp[i][j]) {
                continue;
            }
            queue<pii> q;
            q.emplace(i, j);
            while (!q.empty()) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                int next = path[x][y] + 1;
                for (auto k:mover) {
                    int u = k.first;
                    int v = k.second;
                    if (path[x + u][y + v] == next) {
                        dp[x + u][y + v] = max(dp[x + u][y + v], 1 + dp[x][y]);
                        q.emplace(x + u, y + v);
                    }
                }
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            result = max(result, dp[i][j]);
        }
    }
    cout << result + 1;
    return 0;
}