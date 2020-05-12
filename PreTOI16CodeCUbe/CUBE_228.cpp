#include <bits/stdc++.h>

using namespace std;
using lli = long long;
using pii = pair<lli, lli>;

int main() {
    lli n, m, k, t, u, v, w, temp;
    bool checker = false;
    scanf(" %lld %lld %lld %lld", &n, &m, &k, &t);
    vector<pii> graph[n + 5];
    for (lli i = 0; i < m; ++i) {
        scanf(" %lld %lld %lld", &u, &v, &w);
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }
    vector<pii> dist(n + 5, {2e18, 0});
    vector<bool> visited(n + 5, false);
    priority_queue<pii, vector<pii>, greater<pii>> q;

    dist[1] = {0, 0};
    q.emplace(dist[1].first, 1);
    while (!q.empty()) {
        u = q.top().second;
        q.pop();
        if (visited[u]) {
            continue;
        }
        visited[u] = true;

        if (u == n) {
            checker = true;
            temp = dist[n].first;
            if (dist[n].second > k) {
                temp = dist[n].first - dist[n].second + k;
            }
            if (temp <= t) {
                cout << "Happy Winnie the Pooh :3\n";
                cout << temp << "\n";
            } else {
                cout << "No Honey TT\n";
            }
            break;
        }
        for (auto i:graph[u]) {
            v = i.first, w = i.second;
            if (!visited[v] && dist[u].first + w < dist[v].first) {
                dist[v] = {dist[u].first + w, max(dist[v].second, w)};
                q.emplace(dist[v].first, v);
            }
        }
    }
    if (!checker) {
        cout << "No Honey TT\n";
    }
    return 0;
}
