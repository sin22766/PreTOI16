#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("open2.txt", "r", stdin);
    int n, k, q, l, r, count;
    scanf(" %d %d %d", &n, &k, &q);
    int snack[n];
    vector<int> snack_bag;
    for (int i = 0; i < n; ++i) {
        scanf(" %d", &snack[i]);
    }
    for (int i = 0; i < q; ++i) {
        scanf(" %d %d", &l, &r);
        snack_bag = {snack + l - 1, snack + r};
        sort(snack_bag.begin(), snack_bag.end());
        for (auto j:snack_bag) {
            for (int m = 1; m <= k; ++m) {
                if (j == m) {
                    cout << n
                }
            }
        }
    }
    return 0;
}

