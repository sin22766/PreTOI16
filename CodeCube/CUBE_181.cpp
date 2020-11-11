#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int main() {
    int n, m, p;
    scanf("%d%d%d", &n, &m, &p);
    vector<pii> graph[n];
    for (int i = 0; i < m; ++i) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        graph[x].emplace_back(y, z);
        graph[y].emplace_back(x, z);
    }
    for (int i = 0; i < p; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);

    }
    return 0;
}