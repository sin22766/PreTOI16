#include <bits/stdc++.h>

using namespace std;

int row[110], col[110], row_add[110], col_add[110];

int main() {
    int n, m;
    scanf(" %d %d", &n, &m);
    int temp, sum = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            scanf(" %d", &temp);
            col[j] += temp;
            row[i] += temp;
        }
        sum += row[i];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            scanf(" %d", &temp);
            col_add[j] += temp;
            row_add[i] += temp;
        }
    }
    int max_between = -1e9;
    for (int i = 1; i <= n; ++i) {
        max_between = max(max_between, row_add[i - 1] + row_add[i + 1] - row[i]);
    }
    for (int i = 1; i <= m; ++i) {
        max_between = max(max_between, col_add[i - 1] + col_add[i + 1] - col[i]);
    }
    cout << sum + max_between;
    return 0;
}

