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
    int n, m, u, v, cnt = 0, least = 0;
    stack<pair<int, int>> q;
    cin >> n >> m;
    int parent[n + 1];
    for (int j = 1; j <= n; ++j) {
        parent[j] = j;
    }
    for (int i = 1; i <= m; ++i) {
        scanf(" %d %d", &u, &v);
        q.emplace(u, v);
    }
    while (!q.empty()) {
        u = q.top().first;
        v = q.top().second;
        q.pop();
        cnt++;
        if (find(parent, v) != find(parent, u)) {
            merge(parent, u, v);
            least = cnt;
        }
    }
    cout << m - least;
    return 0;
}