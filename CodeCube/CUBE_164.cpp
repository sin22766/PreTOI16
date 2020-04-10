#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, temp, fst, snd, trd, dif, result = 1e9;
    cin >> n;
    int treasure[n];
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        if (i > 0) {
            treasure[i] = treasure[i - 1] + temp;
        } else {
            treasure[i] = temp;
        }
    }
    for (int i = 0; i < n - 2; ++i) {
        for (int j = i + 1; j < n - 1; ++j) {
            fst = treasure[i];
            snd = treasure[j] - treasure[i];
            trd = treasure[n - 1] - treasure[j];
            dif = max(max(fst, snd), trd) - min(min(fst, snd), trd);
            result = min(result, dif);
        }
    }
    cout << result;
    return 0;
}