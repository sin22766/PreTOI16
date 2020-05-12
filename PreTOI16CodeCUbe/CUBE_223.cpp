#include <bits/stdc++.h>

using namespace std;

int main() {
    pair<int, int> checker[3] = {{0,  -1},
                                 {-1, -1},
                                 {-1, 0}};
    int n, m, sum = 0, minN;
    scanf(" %d %d", &n, &m);
    char temp[m + 10];
    int t = min(n, m);
    int pic[n + 5][m + 5], ans[t + 5];
    memset(ans, 0, t + 5);
    for (int i = 0; i <= n; ++i) {
        if (i) {
            scanf(" %s", &temp);
        }
        for (int j = 0; j <= m; ++j) {
            if (i && j && temp[j - 1] == '1') {
                sum++;
                minN = 1e9;
                for (auto k:checker) {
                    minN = min(minN, pic[i + k.first][j + k.second]);
                }
                pic[i][j] = minN + 1;
                ans[pic[i][j]]++;
            } else {
                pic[i][j] = 0;
            }
            if (j > 1) {
                pic[i - 1][j - 2] = 0;
            }
        }
        pic[i - 1][n] = pic[i - 1][n - 1] = 0;
    }
    for (int T = 0; T < t; ++T) {
        sum -= ans[T];
        cout << sum << "\n";
    }
    return 0;
}