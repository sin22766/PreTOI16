#include <bits/stdc++.h>

using namespace std;

int pic[3][7005];
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
                pic[i % 2][j] = min(pic[i % 2][j - 1], min(pic[(i - 1) % 2][j], pic[(i - 1) % 2][j - 1])) + 1;
                ans[pic[i % 2][j]]++;
            } else {
                pic[i % 2][j] = 0;
            }
        }
    }
    for (int T = 0; T < t; ++T) {
        sum -= ans[T];
        cout << sum << "\n";
    }
    return 0;
}