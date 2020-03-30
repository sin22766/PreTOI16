#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, temp, maxHP = 5000;
    cin >> n >> m;
    int **arr = new int *[n + 5];
    for (int i = 1; i <= n; ++i) {
        arr[i] = new int[n + 5];
        for (int j = 1; j <= m; ++j) {
            cin >> temp;
            arr[i][j] = temp * -1 + 500;
        }
    }
    for (int i = 1; i <= m; ++i) {

    }
    return 0;
}