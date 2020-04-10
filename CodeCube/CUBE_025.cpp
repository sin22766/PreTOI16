#include <bits/stdc++.h>

using namespace std;

int dp[605][605], q[605];

int q_sum(int l, int r) {
    return q[r] - q[l];
}

int solver(int l, int r) {
    if (l == r) {
        return 0;
    }
    if (dp[l][r] != 0) {
        return dp[l][r];
    }
    int sum_A = q_sum(l - 1, l) + q_sum(l, r) + min(q_sum(l - 1, l), q_sum(l, r));
    int sum_B = q_sum(r - 1, r) + q_sum(l - 1, r - 1) + min(q_sum(r - 1, r), q_sum(l - 1, r - 1));
    return dp[l][r] = max(sum_A + solver(l + 1, r), sum_B + solver(l, r - 1));
}

int main() {
    int n, temp;
    cin >> n;

    //input
    for (int i = 1; i <= n; ++i) {
        cin >> temp;
        q[i] = q[i - 1] + temp;
    }
    cout << solver(1, n) << "\n";
    return 0;
}
