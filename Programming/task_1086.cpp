#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k, a, day, max_day = 0, minN, indexer;
    scanf(" %d %d %d", &n, &k, &a);
    int diary[n + 5];
    diary[0] = 0;
    for (int i = 1; i <= n; ++i) {
        scanf(" %d", &diary[i]);
        diary[i] += diary[i - 1];
    }
    for (int i = 1; i < diary[n]; ++i) {
        day = 0;
        indexer = 1;
        for (int j = 0; j <= k; ++j) {
            if (i + (j * a) > (diary[indexer])) {
                indexer++;
            }
        }
        if (day > max_day) {
            max_day = day;
            minN = i;
        }

        if (max_day == n) {
            break;
        }
    }
    cout << minN << " " << max_day;
    return 0;
}