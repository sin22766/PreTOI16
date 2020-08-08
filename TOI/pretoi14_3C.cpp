#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int main() {
    int n, m;

    //Input
    scanf("%d%d", &n, &m);
    vector<int> graph[n];
    vector<pii> graphOrder;
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        graphOrder.emplace_back(u, v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    return 0;
}