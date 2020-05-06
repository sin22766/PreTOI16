#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    long long result = 0;
    scanf(" %d", &n);
    int arr[n];
    for (int i = 0; i < n; ++i) {
        scanf(" %d", &arr[i]);
    }
    for (int i = n - 1; i >= 0; --i) {
        if (result == 0) {
            result = arr[i];
        } else {
            if (result % arr[i] != 0) {
                result = ((result / arr[i]) + 1) * arr[i];
            }
        }
    }
    cout << result;
    return 0;
}
