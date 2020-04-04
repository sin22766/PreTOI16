#include<bits/stdc++.h>

using namespace std;
int n, m, mp[55][55], Q;
bool row[55][55], col[55][55], found;

void backtrack(int i, int j, int k) {
    if (i == n + 1 && j == n && k == m && !found) {
        found = true;
        cout << "Case #" << Q << ": " << "POSSIBLE\n";
        for (int b = 1; b <= n; ++b) {
            for (int v = 1; v <= n; ++v) {
                cout << mp[b][v] << " ";
            }
            cout << "\n";
        }
        exit;
    } else if (j == n + 1) {
        exit;
    }
    if (i > n) {
        backtrack(1, j + 1, k);
    } else {
        for (int t = 1; t <= n && !found; t++) {
            if (!row[i][t] && !col[j][t] && !found) {
                row[i][t] = true;
                col[j][t] = true;
                if (i == j) { k += t; }
                mp[i][j] = t;

                backtrack(i + 1, j, k);

                mp[i][j] = 0;
                row[i][t] = false;
                col[j][t] = false;
                if (i == j) { k -= t; }
            }
        }
    }
}

int main() {
    int k;
    scanf("%d", &k);
    for (Q = 1; Q <= k; Q++) {
        scanf("%d %d", &n, &m);

        backtrack(1, 1, 0);

        if (!found) {
            printf("Case #%d: IMPOSSIBLE\n", Q);
        }
        found = false;
    }

    return 0;
}