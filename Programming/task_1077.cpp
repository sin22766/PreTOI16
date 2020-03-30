#include <bits/stdc++.h>

using namespace std;

int table[1010][1010];

void quick_sum() {
    for (int i = 0; i < 1001; ++i) {
        for (int j = 0; j < 1001; ++j) {
            if (i != 0 && j != 0) {
                table[i][j] += table[i - 1][j] + table[i][j - 1] - table[i - 1][j - 1];
            } else if (j != 0) {
                table[i][j] += table[i][j - 1];
            } else if (i != 0) {
                table[i][j] += table[i - 1][j];
            }
        }
    }
}

int main() {
    int n, m, x, y, x_bottom, y_bottom, k;
    long long result;
    scanf(" %d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf(" %d %d", &x, &y);
        table[y][x]++;
    }
    quick_sum();
    for (int j = 0; j < m; ++j) {
        scanf(" %d %d %d", &x, &y, &k);
        (x + k > 1000) ? x_bottom = 1000 : x_bottom = x + k;
        (y + k > 1000) ? y_bottom = 1000 : y_bottom = y + k;
        (x - k < 0) ? x = 0 : x = x - k;
        (y - k < 0) ? y = 0 : y = y - k;
        result = table[y_bottom][x_bottom];
        if (x > 0 && y > 0) {
            result += table[y - 1][x - 1];
        }
        if (x > 0) {
            result -= table[y_bottom][x - 1];
        }
        if (y > 0) {
            result -= table[y - 1][x_bottom];
        }
        cout << result << "\n";
    }
    return 0;
}