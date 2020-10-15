#include <bits/stdc++.h>

using lli = long long int;
using namespace std;

int main() {
    lli n, maxCat = -1e9, result;
    scanf("%lld", &n);
    lli cat[n];
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &cat[i]);
        if (cat[i] > maxCat) {
            maxCat = cat[i];
        }
    }

    lli l = 0, r = maxCat;
    while (l <= r) {
        lli mid = (l + r) / 2;

        bool checked = true;
        lli previous = -1;
        for (int i = 0; i < n; ++i) {
            if (cat[i] > mid) {
                if (previous == -1) {
                    previous = cat[i];
                } else if (cat[i] == previous) {
                    previous = -1;
                } else {
                    checked = false;
                    break;
                }
            }
        }

        if (checked) {
            result = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << result;
    return 0;
}


