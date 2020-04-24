#include <bits/stdc++.h>

using namespace std;

int main() {
    int m, t = 1, lab;
    long long n;
    cin >> m >> n;
    pair<int, int> labor[m];
    for (int i = 0; i < m; ++i) {
        cin >> lab;
        labor[i] = {lab, 0};
    }
    sort(labor, labor + m);

    while (n > 0) {
        for (auto i:labor) {
            if (t - i.second == i.first) {
                i.second = 0;
            }
            if (!i.second) {
                i.second = t;
                n--;
            }
        }
        t++;
    }
    int result = -1e9;
    for (auto i:labor) {
        i.second += i.first;
        result = max(result, i.second);
    }
    cout << result << "\n";
    return 0;
}