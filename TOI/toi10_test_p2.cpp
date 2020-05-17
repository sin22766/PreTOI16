#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, remain1, remain2, count;
    for (int t = 0; t < 20; ++t) {
        count = 0;
        scanf(" %d %d", &n, &m);
        for (int i = 0; i <= n / 2; ++i) {
            remain1 = n - (i * 2);
            for (int j = 0; j <= remain1 / 2; ++j) {
                remain2 = (n - ((i + j) * 2)) / 4;
                if (i + j + remain2 == m) {
                    count++;
                    cout << i << " " << remain2 << " " << j << "\n";
                    cout << remain2 << "   " << remain2 << "\n";
                    cout << j << " " << remain2 << " " << i << "\n";
                }
            }
        }
        cout << count << "\n";
    }
    return 0;
}

