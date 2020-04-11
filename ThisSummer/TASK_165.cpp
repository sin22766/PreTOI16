#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, d;
    long long a;
    cin >> n >> d;
    long long num[n];
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
    }
    sort(num, num + n);
    long long l = 0, r = 1, count = 0;
    while (r < n) {
        if (num[l] + d >= num[r]) {
            count += r - l;
        } else {
            l = r;
        }
        r++;
    }
    cout << count;
    return 0;
}