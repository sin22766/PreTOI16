#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n, temp, l, r;
    scanf(" %lld", &n);
    ll treasure[n + 1], result = 2e9;
    ll fst, snd, trd;
    treasure[0] = 0;
    for (int i = 1; i <= n; ++i) {
        scanf(" %d", &temp);
        treasure[i] = treasure[i - 1] + temp;
    }
    for (int i = 1; i <= n - 2; ++i) {
        fst = treasure[i];
        l = i + 1, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;

            snd = treasure[mid] - fst;
            trd = treasure[n] - treasure[mid];
            result = min(result, max(fst, max(snd, trd)) - min(fst, min(snd, trd)));
            if (snd >= trd) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
    }
    cout << result << "\n";
    return 0;
}