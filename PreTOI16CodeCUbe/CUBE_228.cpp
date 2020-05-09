#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, k, t;
    scanf(" %d %d %d %d", &n, &m, &k, &t);
    vector<pair<int, int>> graph[n + 5];
    int u, v, w;
    for (int i = 0; i < m; ++i) {
        scanf(" %d %d %d", &u, &v, &w);
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }
    vector<long long> dist(n + 5, 1e9);
    vector<bool> visited(n + 5, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

    vector<int> traveled;
    pair<int, int> parent[n + 10];
    int maxDist = -1e9;
    dist[1] = 0;
    q.emplace(dist[1], 1);
    while (!q.empty()) {
        int a = q.top().second;
        q.pop();
        if (visited[a]) {
            continue;
        }
        visited[a] = true;
        traveled.push_back(a);

        if (a == n) {
            int curr = n;
            while (curr != 1) {
                maxDist = max(maxDist, parent[curr].second);
                curr = parent[curr].first;
            }
            if (maxDist > k) {
                dist[n] = dist[n] - maxDist + k;
            }
            if (dist[n] <= t) {
                cout << "Happy Winnie the Pooh :3\n";
                cout << dist[n] << "\n";
            } else {
                cout << "No Honey TT\n";
            }
            break;
        }
        for (auto i:graph[a]) {
            int b = i.first;
            int c = i.second;
            if (!visited[b] && dist[a] + c < dist[b]) {
                dist[b] = dist[a] + c;
                q.emplace(dist[b], b);
                parent[b] = {a, c};
            }
        }
    }
    for (auto i:traveled) {
        cout << i << " ";
    }
    return 0;
}