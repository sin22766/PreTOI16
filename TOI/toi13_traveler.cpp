#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

vector<int> shortest(vector<pii> graph[], int start, int n) {
    vector<bool> visited(n + 1, false);
    vector<int> dist(n + 1, 1e9);
    priority_queue<pii, vector<pii>, greater<pii>> q;

    dist[start] = 0;
    q.emplace(dist[start], start);

    while (!q.empty()) {
        int u = q.top().second;
        q.pop();

        if (visited[u])
            continue;
        visited[u] = true;

        for (auto i:graph[u]) {
            int w = i.first;
            int v = i.second;
            if (!visited[v] && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                q.emplace(dist[v], v);
            }
        }


    }
    return dist;
}

int main() {
    int n, m, x, y, z;
    scanf("%d %d", &n, &m);
    scanf("%d %d %d", &x, &y, &z);

    vector<pii> graph[n];

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u].emplace_back(w, v);
        graph[v].emplace_back(w, u);
    }

    vector<int> distStart = shortest(graph, x, n);
    vector<int> distEnd = shortest(graph, y, n);

    if (distStart[y] <= z) {
        cout << y << " " << distStart[y] << " " << 0;
    } else {
        vector<pii> pos;
        for (int i = 0; i < n; ++i) {
            if (distStart[i] <= z && i != x) {
                pos.emplace_back(distEnd[i], i);
            }
        }
        sort(pos.begin(),pos.end());
        cout << pos.front().second << " " << distStart[pos.front().second] << " " << pos.front().first;
    }
    return 0;
}