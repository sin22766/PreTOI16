#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

char robot_map[2010][2010];
int dist[2010][2010];

bool checker(int x, int y, int u, int v, int n, int m) {
    return x + u >= 0 && x + u < n && y + v >= 0 && y + v < m;
}


int main() {
    queue<pii> q;
    pair<int, int> mover[] = {{1,  0},
                              {0,  1},
                              {-1, 0},
                              {0,  -1}};

    for (auto &i : dist) {
        for (int &j : i) {
            j = 1e9;
        }
    }

    int n, m;
    scanf("%d %d", &n, &m);

    vector<pii> target;

    for (int i = 0; i < n; ++i) {
        scanf("%s", &robot_map[i]); // "i" is Row,"j" is Column
        for (int j = 0; j < m; ++j) {
            if (robot_map[i][j] == 'X') {
                dist[i][j] = 0;
                q.emplace(i, j);
            } else if (robot_map[i][j] == 'A') {
                target.emplace_back(i, j);
            }
        }
    }

    int x, y, u, v;

    while (!q.empty()) {
        tie(x, y) = q.front();
        q.pop();

        for (auto i: mover) {
            tie(u, v) = i;
            if (checker(x, y, u, v, n, m) && dist[x][y] + 1 < dist[x + u][y + v] && robot_map[x][y] != 'W') {
                dist[x + u][y + v] = dist[x][y] + 1;
                q.emplace(x + u, y + v);
            }
        }
    }

    int targetCount = 0, SumWay = 0;

    for (auto i: target) {
        if (dist[i.first][i.second] != 1e9) {
            targetCount++;
            SumWay += dist[i.first][i.second];
        }
    }
    cout << targetCount << " " << SumWay * 2;
    return 0;
}

