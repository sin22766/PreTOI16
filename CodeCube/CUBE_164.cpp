#include <bits/stdc++.h>

using namespace std::chrono;
using namespace std;

int main() {
    int n, temp, fst, l, r, dif = 1e9, result = 1e9, mid;
    scanf(" %d", &n);
    int treasure[n];
    for (int i = 0; i < n; ++i) {
        scanf(" %d", &temp);
        if (i > 0) {
            treasure[i] = treasure[i - 1] + temp;
        } else {
            treasure[i] = temp;
        }
    }
    for (int i = 0; i < n - 2; ++i) {
        fst = treasure[i];
        temp = treasure[n - 1] - treasure[i];
        l = i, r = n - 1;
        mid = (l + r) / 2;
        while (l <= r) {
            dif = min(dif, abs((treasure[n - 1] - treasure[mid]) - (treasure[mid] - treasure[i])));
            if (treasure[mid] - treasure[l] > temp / 2) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        result = min(result, abs(fst - dif));
    }
    cout << result;
    return 0;
}