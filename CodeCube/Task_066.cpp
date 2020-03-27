#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err34-c"

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, temp;
    cin >> n >> m;
    int village[n + 10][m + 10];
    vector<pair<int, int>> infected;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf(" %d", &village[i][j]);
            if (village[i][j] == 0) {
                infected.emplace_back(i, j);
            }
        }
    }
    return 0;
}