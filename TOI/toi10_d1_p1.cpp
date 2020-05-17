#include <bits/stdc++.h>

using namespace std;

bool used[40010];

int main() {
    int m, n, temp, u, v;
    char dir;
    scanf(" %d %d", &m, &n);
    temp = m * n - 1;
    int num[m][n];
    vector<pair<int, char>> graph[m * n];
    for (int i = 0; i < temp; ++i) {
        scanf(" %d %c %d", &u, &dir, &v);
        graph[u].emplace_back(v, dir);
        if (dir == 'U') {
            graph[v].emplace_back(u, 'D');
        } else {
            graph[v].emplace_back(u, 'R');
        }
        used[v] = true;
    }
    vector<bool> visited;
    int visit;
    queue<tuple<int, int, int>> q;
    for (int i = 0; i < n * m; ++i) {
        if (!used[i]) {
            visited.assign(m * n + 10, false);
            visit = 0;
            q.emplace(i, 0, 0);
            while (!q.empty()) {
                int x = get<0>(q.front());
                int dir_x = get<1>(q.front());
                int dir_y = get<2>(q.front());
                q.pop();

                visited[x] = true;
                visit++;

                if (dir_x < 0 || dir_x >= n || dir_y < 0 || dir_y >= m) {
                    break;
                }

                if (dir_y < 0) {
                    dir_y = 0;
                }
                num[dir_y][dir_x] = x;

                for (auto j:graph[x]) {
                    int y = j.first;
                    char d = j.second;

                    if (visited[y]) {
                        continue;
                    }
                    visited[y] = true;
                    if (d == 'U') {
                        q.emplace(y, dir_x, dir_y + 1);
                    } else if (d == 'L') {
                        q.emplace(y, dir_x + 1, dir_y);
                    } else if (d == 'D') {
                        q.emplace(y, dir_x, dir_y - 1);
                    } else {
                        q.emplace(y, dir_x - 1, dir_y);
                    }
                }
            }
            if (visit == m * n) {
                break;
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << num[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}