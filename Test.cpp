#include<bits/stdc++.h>

using namespace std;
using lli = long long;
using pii = pair<int, int>;
using pipii = pair<int, pii>;
int dis[350][2000];

int main() {
    int n, m, t, st, en;
    scanf("%d%d%d", &n, &m, &t);
    scanf("%d%d", &st, &en);
    vector<pipii> ve[n + 10];
    for (int i = 0; i < m; i++) {
        int u, v, c, w;
        scanf("%d%d%d%d", &u, &v, &c, &w);
        ve[v].push_back({u, {c, w}});
        ve[u].push_back({v, {c, w}});
    }
    for (auto x:ve[st]) {
        int v = x.first;
        int c = x.second.first;
        int w = x.second.second;
        dis[v][w] = c;
    }
    for (int j = 1; j <= t; j++) {
        for (int i = 1; i <= n; i++) {
            if (dis[i][j] != 0) {
                for (auto x:ve[i]) {
                    int v = x.first;
                    int joy = x.second.first;
                    int w = x.second.second;

                    if (j + w > t) continue;

                    dis[v][w + j] = max(dis[v][w + j], dis[i][j] + joy);
                }
            }
        }
    }
    int mx = -1;
    for (int i = 1; i <= t; i++) {
        if (dis[en][i] == 0) continue;
        mx = max(mx, dis[en][i]);
    }
    if (mx == -1) cout << "Impossible";
    else cout << mx;
}