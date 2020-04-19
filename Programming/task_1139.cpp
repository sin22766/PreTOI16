#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x, y, s, maxX = 0, maxY = 0, minX = 1e9, minY = 1e9;
    long long targetX = 1e18, targetY = 1e18;
    scanf(" %d", &n);
    vector<tuple<int, int, int>> dorm;
    for (int i = 0; i < n; ++i) {
        scanf(" %d %d %d", &x, &y, &s);
        maxX = max(x, maxX);
        maxY = max(y, maxY);
        minX = min(x, minX);
        minY = min(y, minY);
        dorm.emplace_back(x, y, s);
    }
    long long dist = 0, distNext = 0;
    int l1 = minX, l2 = minY, r1 = maxX, r2 = maxY;
    while (l1 <= r1 || l2 <= r2) {
        if (l1 <= r1) {
            long long mid1 = (l1 + r1) / 2;
            dist = distNext = 0;
            for (auto i:dorm) {
                dist += abs(get<0>(i) - mid1) * get<2>(i);
                distNext += abs(get<0>(i) - mid1 + 1) * get<2>(i);
            }
            targetX = min(targetX, min(dist, distNext));
            if (distNext <= dist) {
                r1 = mid1 - 1;
            } else {
                l1 = mid1 + 1;
            }
        }
        if (l2 <= r2) {
            long long mid2 = (l2 + r2) / 2;
            dist = distNext = 0;
            for (auto i:dorm) {
                dist += abs(get<1>(i) - mid2) * get<2>(i);
                distNext += abs(get<1>(i) - mid2 + 1) * get<2>(i);
            }
            targetY = min(targetY, min(dist, distNext));
            if (distNext <= dist) {
                r2 = mid2 - 1;
            } else {
                l2 = mid2 + 1;
            }
        }
    }

    cout << targetX + targetY;

    return 0;
}
