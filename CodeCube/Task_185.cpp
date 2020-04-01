#include <bits/stdc++.h>

using namespace std;
using tlii = tuple<long long, int, int>;
using pil = pair<int, long long>;

long long shortest(vector<pil> graph[], int n, int start, int target, int t) {
    vector<long long> dis[n + 1];
    vector<bool> visited[n + 1];
    for (int i = 0; i <= n; ++i) {
        dis[i].assign(t, LLONG_MAX);
        visited[i].assign(t, false);
    }
    priority_queue<tlii, vector<tlii>, greater<tlii>> q;
    dis[start][1 % t] = 0;
    q.emplace(dis[start][1 % t], start, 1 % t);
    while (!q.empty()) {
        int u = get<1>(q.top());
        int curr = get<2>(q.top());
        q.pop();
        if (visited[u][curr]) {
            continue;
        }
        if (u == target && curr == 0) {
            return dis[u][curr];
        }
        visited[u][curr] = true;
        for (auto i:graph[u]) {
            int v = i.first;
            long long w = i.second;
            if (!visited[v][(curr + 1) % t] && dis[u][curr] + w < dis[v][(curr + 1) % t]) {
                dis[v][(curr + 1) % t] = dis[u][curr] + w;
                q.emplace(dis[v][(curr + 1) % t], v, (curr + 1) % t);
            }
        }
    }
    return -1;
}

int main() {
    int n, m, t, u, v, x, y;
    long long w;
    cin >> n >> m >> t >> x >> y;
    vector<pil> graph[n + 1];
    for (int i = 1; i <= m; ++i) {
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
    }
    cout << shortest(graph, n, x, y, t);
    return 0;
}