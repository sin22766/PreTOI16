#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, k, temp, cX, cY, maxN = 0;
    cin >> n >> m >> k;
    int x[k], y[k], r[k];
    for (int i = 0; i < k; ++i) {
        cin >> x[i] >> y[i] >> r[i];
    }

    temp = max(n, m);
    for (int i = 0; i < temp; ++i) {
        cX = cY = 0;
        for (int j = 0; j < k; ++j) {
            if (i < n && i <= x[j] + r[j] && i >= x[j] - r[j]) {
                cX++;
            }
            if (i < m && i <= y[j] + r[j] && i >= y[j] - r[j]) {
                cY++;
            }
        }
        maxN = max(cX, max(cY, maxN));
    }
    cout << maxN;
    return 0;
}