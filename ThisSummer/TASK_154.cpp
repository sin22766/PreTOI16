#include <bits/stdc++.h>

using namespace std;

void shortest(vector<pair<int, int>> *graph, vector<int> &dist,vector<bool> &visited, int start, int power,int n) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;

    dist[start] = 0;
    q.emplace(dist[start], start);

    while (!q.empty()) {
        int u = q.top().second,d = q.top().first;
        q.pop();
        if(visited[u]||d > power)
            continue;
        visited[u] = true;

        for (auto i:graph[u]) {
            int v = i.first;
            int w = i.second;
            if(!visited[v] && dist[u]+w < dist[v]){
                dist[v] = dist[u]+w;
                q.emplace(dist[v],v);
            }
        }
    }
}

int main() {
    int n, m, k, u, v, w;
    cin >> n >> m >> k;
    vector<bool> visited(n, false);
    vector<int> dist(n, 1e9);
    vector<pair<int, int>> graph[n];
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        graph[u-1].emplace_back(v-1, w-1);
    }
    shortest(graph,dist,visited,0,k,n);
    return 0;
}
