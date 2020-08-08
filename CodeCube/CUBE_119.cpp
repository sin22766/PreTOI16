#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

const int N = 105, M = 10005;
int A[N][M], dp[N][M];

int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    int direction[n + 5][m + 5];
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            scanf(" %d", &direction[i][j]);
        }
    }

    priority_queue<pii, vector<pii>, greater<pii>> Q;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            Q.emplace(dp[i - 1][j], j);
            while (!Q.empty() && Q.top().second < j - k) {
                Q.pop();
            }
            dp[i][j] = Q.top().first + A[i][j];
        }
    }
    int maxN = -1e9;
    for (auto i:dp[n - 1]) {
        maxN = max(i, maxN);
    }
    cout << maxN;
    return 0;
}

