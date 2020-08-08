#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
const int N = 500010;
int A[N];

int main() {
    int n, k, dp;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &A[i]);
    deque<pii> Q;
    dp = A[1];
    for (int i = 2; i <= n; ++i) {
        while (!Q.empty() && Q.back().first >= dp) {
            Q.pop_back();
        }

        Q.emplace_back(dp, i - 1);

        while (!Q.empty() && Q.front().second < i - k) {
            Q.pop_front();
        }

        dp = Q.front().first + A[i];
    }
    printf("%d\n", dp);
    return 0;
}

