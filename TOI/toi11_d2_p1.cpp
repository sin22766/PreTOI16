#include <bits/stdc++.h>

using namespace std;

int main() {
    int m, temp = 2e9;
    long long n, l, r, result = 0;
    cin >> m >> n;
    int labor[m];
    for (int i = 0; i < m; ++i) {
        scanf(" %d", &labor[i]);
        temp = min(temp, labor[i]);
    }
    l = temp, r = temp * n;

    while (l <= r) {
        long long mid = (l + r) / 2, sum = 0;
        for (int i = 0; i < m; ++i) {
            sum += mid / labor[i];
        }
        if (sum >= n) {
            r = mid - 1;
            result = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << result << "\n";
    return 0;
}