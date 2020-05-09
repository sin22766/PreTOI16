#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, t, sum = 0;
    bool breaker;
    scanf(" %d %d", &n, &m);
    char temp[m];
    t = min(n, m);
    vector<vector<int>> pic(n, vector<int>(m, 0)), pic_cpy;
    for (int i = 0; i < n; ++i) {
        scanf(" %s", &temp);
        for (int j = 0; j < m; ++j) {
            pic[i][j] = temp[j] - '0';
            sum += pic[i][j];
        }
    }
    cout << sum << "\n";
    for (int T = 1; T < t; ++T) {
        sum = 0;
        for (int i = 0; i < n - T; ++i) {
            for (int j = 0; j < m - T; ++j) {
                breaker = false;
                for (int k = i; k <= i + T; ++k) {
                    if (breaker) {
                        break;
                    }
                    for (int l = j; l <= j + T; ++l) {
                        if (k >= n - T + 1 || l >= m - T + 1) {
                            continue;
                        }
                        if (pic[k][l] == 0) {
                            pic[i][j] = 0;
                            breaker = true;
                            break;
                        }
                    }
                }
                sum += pic[i][j];
            }
        }
        cout << sum << "\n";
    }
    return 0;
}