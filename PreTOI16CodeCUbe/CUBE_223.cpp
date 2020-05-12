#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, sum = 0;
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
            if (!i || !j) {
                pic[i][j] = 0;
                continue;
            }
            if (temp[j - 1] == '1') {
                sum++;
                pic[i][j] = min(pic[i][j - 1], min(pic[i - 1][j], pic[i - 1][j - 1])) + 1;
                ans[pic[i][j]]++;
            } else {
                pic[i][j] = 0;
            }
        }
    }
    for (int T = 0; T < t; ++T) {
        sum -= ans[T];
        cout << sum << "\n";
    }
    return 0;
}