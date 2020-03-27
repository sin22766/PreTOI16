#include <bits/stdc++.h>

using namespace std;

void shortest(vector<pair<int, long long>> *graph, vector<long long> &dist, vector<bool> &visited, int start) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;

    dist[start] = 0;
    q.emplace(dist[start], start);

    while (!q.empty()) {
        int u = q.top().second;
        long long d = q.top().first;
        q.pop();
        if (visited[u]) {
            continue;
        }
        visited[u] = true;

        for (auto i:graph[u]) {
            int v = i.first;
            long long w = i.second;
            if (!visited[v] && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                q.emplace(dist[v], v);
            }
        }
    }
}

int main() {
    int n, m, u, v;
    long long k, w;
    cin >> n >> m >> k;
    vector<bool> visited(n + 1, false);
    vector<long long> dist(n + 1, 1e15);
    vector<pair<int, long long>> graph[n + 1];
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }
    shortest(graph, dist, visited, 1);
    for (int j = n; j >= 1; --j) {
        if (dist[j] <= k) {
            cout << j << "\n";
            break;
        }
    }
    return 0;
}
