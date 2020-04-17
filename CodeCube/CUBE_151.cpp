#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int main() {
    int n, m, k, t;
    int p, s;
    cin >> n >> m >> k >> t;
    vector<pii> shoe;
    vector<tuple<int, int, int>> graph[n + 1];
    int t_u, t_v, t_d, t_t;
    for (int i = 0; i < m; ++i) {
        cin >> t_u >> t_v >> t_d >> t_t;
        graph[t_u].emplace_back(t_v, t_d, t_t);
        graph[t_v].emplace_back(t_u, t_d, t_t);
    }
    for (int i = 0; i < k; ++i) {
        cin >> p >> s;
        shoe.emplace_back(s, p);
    }
    sort(shoe.begin(), shoe.end());
    //Binary Search
    int l = 0, r = k - 1;
    long long minN = 2e18;
    while (l <= r) {
        long long mid = (l + r) / 2;

        //Djisktra

        priority_queue<pii, vector<pii>, greater<pii>> q;
        bool visited[n + 1];
        long long dist[n + 1];
        for (int i = 0; i <= n; ++i) {
            visited[i] = false;
            dist[i] = 1e10;
        }

        dist[1] = 0;
        q.emplace(0, 1);

        while (!q.empty()) {
            int u = q.top().second;
            q.pop();

            if (visited[u]) {
                continue;
            }

            visited[u] = true;

            for (auto i:graph[u]) {
                int v = get<0>(i);
                int d = get<1>(i);
                int w = get<2>(i);
                if (shoe[mid].first >= d && !visited[v] && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    q.emplace(dist[v], v);
                }
            }
        }

        if (dist[n] <= t) {
            minN = mid;
            r = (int) mid - 1;
        } else {
            l = (int) mid + 1;
        }
    }
    int price = 1e9;

    if (minN == (long long) 2e18) {
        cout << "-1";
    } else {
        for (int i = minN; i < k; ++i) {
            price = min(price, shoe[i].second);
        }
        cout << price;
    }
    return 0;
}