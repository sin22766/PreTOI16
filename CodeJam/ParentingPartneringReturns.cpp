#include <bits/stdc++.h>

using namespace std;
using tiii = tuple<int, int, int>;

int main() {
    int n, T, pre_c, pre_j, st, en;
    bool possible;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        possible = true;
        pre_c = pre_j = 0;
        vector<tiii> q;
        cin >> n;
        string result;
        for (int i = 0; i < n; ++i) {
            cin >> st >> en;
            result.push_back('.');
            q.emplace_back(st, en, i);
        }
        while (!q.empty()) {
            int start = get<0>(q.back());
            int end = get<1>(q.back());
            int i = get<2>(q.back());
            q.pop_back();

            if (pre_c <= start) {
                result[i] = 'C';
                pre_c = end;
            } else if (pre_j <= start) {
                result[i] = 'J';
                pre_j = end;
            } else {
                possible = false;
                break;
            }
        }
        cout << "Case #" << t << ": ";
        if (possible) {
            cout << result << "\n";
        } else {
            cout << "IMPOSSIBLE\n";
        }
    }
    return 0;
}