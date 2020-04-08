#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, d, c, maxC = 0;
    long double max = -3e9;
    long long tD = 0, maxD = 0;
    cin >> n;
    pair<int, int> worm[n];
    for (int i = 0; i < n; ++i) {
        cin >> d >> c;
        worm[i] = {c, d};
    }
    sort(worm, worm + n);

    for (auto i:worm) {
        tD += i.second;
        c = i.first;
        if (max < (double) tD / (double) c) {
            maxD = tD;
            maxC = c;
            max = (double) tD / (double) c;
        }
    }
    cout << maxD << " " << maxC;
    return 0;
}