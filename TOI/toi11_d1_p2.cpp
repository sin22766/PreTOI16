#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
int m, n;
//pii **parent;

pii mover[4] = {{-1, 0},
                {0,  -1},
                {-1, -1},
                {-1, 1}};

/*pii find(pii i) {
    if (parent[i.first][i.second] != i) {
        parent[i.first][i.second] = find(parent[i.first][i.second]);
    }
    return i;
}

void merge(pii i, pii j) {
    pii tempI = find(i);
    parent[tempI.first][tempI.second] = find(j);
}*/

int main() {
    int sum = 0;
    bool check = false;
    cin >> m >> n;
    char map[m][n], mapC[m][n];
    for (int i = 0; i < m; ++i) {
        scanf("%s", map[i]);
        strcpy(mapC[i], map[i]);
        for (int j = 0; j < n; ++j) {
            if (map[i][j] == '1') {
                sum++;
                for (auto k:mover) {
                    if (i + k.first >= 0 && j + k.second >= 0 && map[i + k.first][j + k.second] == '1') {
                        map[i][j] = '0';
                        sum--;
                        break;
                    }
                }
            }
        }
    }
    cout << sum << "\n";
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}