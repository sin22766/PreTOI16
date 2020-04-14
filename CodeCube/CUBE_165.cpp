#include <bits/stdc++.h>

using namespace std;

int find(int parent[], int i) {
    if (parent[i] != i) {
        return parent[i] = find(parent, parent[i]);
    }
    return i;
}

void merge(int parent[], int i, int j) {
    parent[find(parent, i)] = find(parent, j);
}

int main() {
    int n, m, k, l, r, result = 0, temp, x, y, z, mid, checker;
    bool check;
    scanf(" %d %d %d", &n, &m, &k);
    int parent[n + 1];
    vector<int> type[k + 1];
    vector<tuple<int, int, int>> q, b;
    for (int i = 1; i <= n; ++i) {
        cin >> temp;
        type[temp].push_back(i);
    }
    for (int i = 0; i < m; ++i) {
        scanf(" %d %d %d", &x, &y, &z);
        b.emplace_back(z, x, y);
    }
    sort(b.begin(), b.end());

    l = get<0>(b.front());
    r = get<0>(b.back());

    while (l <= r) {
        mid = (l + r) / 2;
        q = b;
        //Check
        check = true;
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }
        while (!q.empty()) {
            int u = get<1>(q.back());
            int v = get<2>(q.back());
            int w = get<0>(q.back());
            q.pop_back();
            if (w <= mid) {
                break;
            }
            merge(parent, u, v);
        }
        temp = q.size() + 1;
        for (int i = 1; i <= k; ++i) {
            checker = 0;
            for (int j:type[i]) {
                if (checker == 0) {
                    checker = find(parent, j);
                } else if (checker != find(parent, j)) {
                    check = false;
                }
            }
        }
        if (check) {
            l = mid + 1;
            result = temp;
        } else {
            r = mid - 1;
        }
    }
    cout << result;
    return 0;
}