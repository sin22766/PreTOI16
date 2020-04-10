#include <bits/stdc++.h>

using namespace std;

int main() {
    int m, o, l = 0, r = 0, result = 1e9;
    cin >> m >> o;
    int bandwidth[o];
    for (int i = 0; i < o; ++i) {
        cin >> bandwidth[i];
        l = max(bandwidth[i], l);
        r += bandwidth[i];
    }
    while (l <= r) {
        int wires = 1, curr_line = 0;
        int mid = (r + l) / 2;

        for (int i = 0; i < o; ++i) {
            if (curr_line + bandwidth[i] > mid) {
                curr_line = 0;
                wires++;
            }
            curr_line += bandwidth[i];
        }
        if (wires > m) {
            l = mid + 1;
        } else {
            result = min(result, mid);
            r = mid - 1;
        }
    }
    cout << result;
    return 0;
}