#include <bits/stdc++.h>

using namespace std;

bool sorter(tuple<int, int, int> item1, tuple<int, int, int> item2) {
    int x1, y1, z1, x2, y2, z2;
    tie(x1, y1, z1) = item1;
    tie(x2, y2, z2) = item2;
    if (x1 != x2) {
        return x1 < x2;
    } else {
        if (y1 != y2) {
            return y1 > y2;
        } else {
            if (y1 == 1) {
                return z1 > z2;
            } else {
                return z1 < z2;
            }
        }
    }
}

int main() {
    int n, old = 0;
    scanf("%d", &n);
    vector<tuple<int, int, int>> event;
    for (int i = 0; i < n; ++i) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        event.emplace_back(x, 1, z);
        event.emplace_back(y, -1, z);
    }
    sort(event.begin(), event.end(), sorter);
    multiset<int> curr = {0};
    multiset<int>::iterator itr;
    for (auto i:event) {
        int u = get<0>(i);
        int state = get<1>(i);
        int h = get<2>(i);
        if (state == 1) {
            curr.insert(h);
        } else {
            curr.erase(curr.find(h));
        }
        itr = curr.end();
        itr--;
        if (*itr != old) {
            cout << u << " " << *itr << "\n";
            old = *itr;
        }
    }
    return 0;
}