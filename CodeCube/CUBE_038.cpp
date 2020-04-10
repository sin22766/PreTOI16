#include <bits/stdc++.h>

using namespace std;

pair<int, int> mover[4] = {{-1, 0},
                           {0,  1},
                           {1,  0},
                           {0,  -1}};


int main() {
    int n, temp, nR, nC;
    cin >> n;
    int game[n][n], dist[n][n];
    bool visited[n][n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> game[i][j];
            dist[i][j] = 1e9;
            visited[i][j] = false;
        }
    }

    //bfs
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> q;
    q.emplace(0, 0, 0);
    dist[0][0] = 0;
    while (!q.empty()) {
        int w = get<0>(q.top());
        int r = get<1>(q.top());
        int c = get<2>(q.top());
        q.pop();

        if (r == n - 1 && c == n - 1) {
            break;
        }

        if (visited[r][c]) {
            continue;
        }

        visited[r][c] = true;
        for (auto i:mover) {
            nR = r;
            nC = c;
            temp = w;
            while (nR + i.first >= 0 && nR + i.first < n && nC + i.second >= 0 && nC + i.second < n &&
                   game[nR + i.first][nC + i.second] != 1) {
                nR += i.first;
                nC += i.second;
                temp++;
            }
            if (!visited[nR][nC] && temp < dist[nR][nC]) {
                dist[nR][nC] = temp;
                q.emplace(temp, nR, nC);
            }
        }
    }
    cout << dist[n - 1][n - 1];
    return 0;
}