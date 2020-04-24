#include <bits/stdc++.h>

using namespace std;

int find(int parent[], int i) {
    if (parent[i] != i) {
        return parent[i] = find(parent, parent[i]);
    }
    return i;
}

void merge(int parent[], int i, int j) {
    parent[find(parent, i)] = find(parent, j);
}

int main() {
    int n, m;
    scanf(" %d %d", &n, &m);
    int parent[n + 1];
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
    }
    vector<tuple<int, int, int>> edges;
    int s, d, l;
    for (int i = 0; i < m; ++i) {
        scanf(" %d %d %d", &s, &d, &l);
        edges.emplace_back(-l, s, d);
    }

    sort(edges.begin(), edges.end());
    long long sum = 0;
    for (auto i:edges) {
        if (find(parent, get<1>(i)) == find(parent, get<2>(i))) {
            continue;
        }
        sum += get<0>(i) + 1;
        merge(parent, get<1>(i), get<2>(i));
    }
    cout << -sum;
    return 0;
}