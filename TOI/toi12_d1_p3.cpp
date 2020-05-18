#include <bits/stdc++.h>

using namespace std;

int find(int parent[], int i) {
    if (i != parent[i]) {
        return parent[i] = find(parent, parent[i]);
    }
    return i;
}

void merge(int parent[], int i, int j) {
    parent[find(parent, i)] = find(parent, j);
}

int main() {
    int n, m, u, v, w;
    scanf(" %d %d", &n, &m);
    int parent[n + 5];
    for (int i = 0; i < n + 5; ++i) {
        parent[i] = i;
    }
    vector<tuple<int, int, int>> edges;
    vector<pair<int, int>> graph[n + 5];
    for (int i = 0; i < m; ++i) {
        scanf(" %d %d %d", &u, &v, &w);
        edges.emplace_back(w, u, v);
    }
    int s, d, p;
    scanf(" %d %d %d", &s, &d, &p);

    sort(edges.begin(), edges.end(), greater<tuple<int, int, int>>());

    for (auto edge:edges) {
        w = get<0>(edge);
        u = get<1>(edge);
        v = get<2>(edge);

        if (find(parent, u) == find(parent, v)) {
            continue;
        }

        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);

        merge(parent, u, v);
    }

    pair<int, int> old[n + 5];
    vector<bool> visited(n + 5, false);
    queue<int> q;
    q.emplace(s);
    visited[s] = true;
    while (!q.empty()) {
        u = q.front();
        q.pop();

        if (u == d) {
            int i = d;
            int minN = 1e9;
            do {
                minN = min(minN, old[i].second);
                i = old[i].first;
            } while (i != s);
            int guide = (int) ceil((double) p / (minN - 1));
            cout << guide << '\n';
        }

        for (auto i:graph[u]) {
            v = i.first;
            w = i.second;
            if (!visited[v]) {
                q.emplace(v);
                old[v] = {u, w};
                visited[v] = true;
            }
        }
    }
    return 0;
}
