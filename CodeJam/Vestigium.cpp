#include <bits/stdc++.h>

using namespace std;

int main() {
    int t, n, temp, trace, r, c;
    set<int> row;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        trace = r = c = 0;
        scanf(" %d", &n);
        set<int> col[n];
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                scanf("%d", &temp);
                if (j == k) {
                    trace += temp;
                }
                col[k].insert(temp);
                row.insert(temp);
            }
            if (row.size() != n) {
                r++;
            }
            row.clear();
        }
        for (int l = 0; l < n; ++l) {
            if (col[l].size() != n) {
                c++;
            }
        }
        cout << "Case #" << t << ": " << trace << " " << r << " " << c << "\n";
    }
    return 0;
}
