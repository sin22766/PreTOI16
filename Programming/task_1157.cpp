#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
const int N = 500010;
int A[N], dp[N];

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &A[i]);
    deque<pii> Q;
    dp[1] = A[1];
    for (int i = 2; i <= n; ++i) {
        dp[i] = 1e9;
        while (!Q.empty() && Q.back().first >= dp[i - 1]) {
            Q.pop_back();
        }

        Q.emplace_back(dp[i - 1], i - 1);

        while (!Q.empty() && Q.front().second < i - k) {
            Q.pop_front();
        }
        dp[i] = Q.front().first + A[i];
    }
    printf("%d\n", dp[n]);
    return 0;
}

