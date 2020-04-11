#include <bits/stdc++.h>
using namespace std::chrono;
using namespace std;

int main() {
    auto start = high_resolution_clock::now();
    freopen("out.txt", "r", stdin);
    int n, temp, fst, snd, trd, dif, result = 1e9;
    scanf(" %d", &n);
    int treasure[n];
    for (int i = 0; i < n; ++i) {
        scanf(" %d", &temp);
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
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << duration.count() << endl;
    return 0;
}