#include <bits/stdc++.h>

using namespace std;
using tlii = tuple<long long, int, int>;

long long Solver(int n, int m, int d) {
    int temp;
    set<pair<int, int>> visited;//ขี้เกียจแก้แล้วเลยใช้set เลย
    priority_queue<tlii, vector<tlii>, greater<tlii>> q;
    q.emplace(0, 0, 0);
    while (!q.empty()) {
        long long count = get<0>(q.top());
        int u = get<1>(q.top());
        int v = get<2>(q.top());
        q.pop();

        if (u == d || v == d) {
            return count;
        }

        if (visited.count({u, v})) {
            continue;
        }

        visited.emplace(u, v);

        if (u < n) {
            q.emplace(count + 1, n, v);
        }
        if (v < m) {
            q.emplace(count + 1, u, m);
        }

        if (u > 0) {
            q.emplace(count + 1, 0, v);
        }
        if (v > 0) {
            q.emplace(count + 1, u, 0);
        }

        if (u > 0 && v < m) {
            temp = v;
            v = (u + v > m) ? m : u + v;
            u = (m - temp < u) ? u - (m - temp) : 0;
            q.emplace(count + 1, u, v);
        }
        if (v > 0 && u < n) {
            temp = u;
            u = (u + v > n) ? n : u + v;
            v = (n - temp < v) ? v - (n - temp) : 0;
            q.emplace(count + 1, u, v);
        }
    }
    return -1;
}

int main() {
    int t, n, m, d;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> n >> m >> d;
        cout << Solver(n, m, d) << "\n";
    }
    return 0;
}