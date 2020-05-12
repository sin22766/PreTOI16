#include <bits/stdc++.h>

using namespace std;

int pic[7005][7005];
int ans[7005];

int main() {
    int n, m, sum = 0;
    scanf(" %d %d", &n, &m);
    char temp[m + 10];
    int t = min(n, m);
    for (int i = 1; i <= n; ++i) {
        scanf(" %s", &temp);
        for (int j = 1; j <= m; ++j) {
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