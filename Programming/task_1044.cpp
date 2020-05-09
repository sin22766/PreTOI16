#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    scanf(" %d %d", &n, &m);
    int row[n], col[m], temp;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf(" %d", &temp);
            if (i == 0) {
                col[j] = temp;
            } else {
                col[j] += temp;
            }
            if (j == 0) {
                row[i] = temp;
            } else {
                row[i] += temp;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf(" %d", &temp);
            col[j] += temp;
            row[i] += temp;
        }
    }
    int sum = 0, minN = 1e9, minM = 1e9;
    for (int i = 0; i < n; ++i) {
        sum += row[i];
        minN = min(minN, row[i]);
    }
    for (int i = 0; i < m; ++i) {
        minM = min(minM, col[i]);
    }

    cout << max(sum - minN, sum - minM);
    return 0;
}

