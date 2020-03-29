#include <bits/stdc++.h>

using namespace std;

void top_sort(vector<int> *graph, vector<int> &visited, int u, queue<int> &q, bool &check) {
    visited[u] = 1;
    for (auto v: graph[u]) {
        if (visited[v] == 0) {
            top_sort(graph, visited, v, q, check);
        } else if (visited[v] == 1) {
            check = true;
        }
    }
    visited[u] = 2;
    q.push(u);
}

int main() {
    int n, m, u, v;
    bool check;
    string result;
    cin >> n >> m;
    vector<int> chain[n + 5];
    vector<int> visited(n + 5, 0);
    queue<int> q;

    //input
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        chain[u].push_back(v);
    }
    for (int i = 1; i <= n; ++i) {
        check = false;
        if (!visited[i]) {
            top_sort(chain, visited, i, q, check);
        }
        if (check) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}
