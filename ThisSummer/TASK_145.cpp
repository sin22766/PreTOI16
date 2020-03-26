#include <bits/stdc++.h>

using namespace std;

//ลองถึกๆดู
bool BFS(vector<int> *graph, vector<bool> &visited, int &start, int &target) {
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        visited[u] = true;
        if (u == target) {
            return true;
        }
        for (auto i : graph[u]) {
            if (!visited[i]) {
                q.push(i);
            }
        }
    }
    return false;
}

int main() {
    int n, m, q;
    cin >> n >> m;
    vector<int> graph[n];
    vector<bool> visited;
    int u, v;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        graph[u - 1].push_back(v - 1);
        graph[v - 1].push_back(u - 1);
    }
    cin >> q;
    for (int i = 0; i < q; ++i) {
        cin >> u >> v;
        u--, v--;
        visited.assign(n, false);
        (BFS(graph, visited, u, v)) ? cout << "Yes\n" : cout << "No\n";
    }
    return 0;
}
