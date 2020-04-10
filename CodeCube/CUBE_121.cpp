#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, pair<int, int>>;

int find(int parent[], int u) {
    if (parent[u] != u) {
        return parent[u] = find(parent, parent[u]);
    } else {
        return u;
    }
}

void merge(int parent[], int u, int v) {
    parent[find(parent, v)] = find(parent, u);
}

int main() {
    //initialize
    int n, m, u, v, remains = 0;

    //input
    cin >> n;
    int strength[n], parent[n];
    for (int i = 0; i < n; ++i) {
        cin >> strength[i];
        parent[i] = i;
    }
    cin >> m;
    vector<pii> edges;
    for (int j = 0; j < m; ++j) {
        cin >> u >> v;
        edges.push_back({strength[u - 1] + strength[v - 1], {u - 1, v - 1}});
    }
    sort(edges.begin(), edges.end());
    for (auto edge:edges) {
        if (find(parent, edge.second.first) == find(parent, edge.second.second)) {
            continue;
        }
        remains += edge.first;
        merge(parent, edge.second.first, edge.second.second);
    }
    cout << remains;
    return 0;
}