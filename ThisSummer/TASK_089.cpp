#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, maxSum, maxEnd, temp;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        if (!i) {
            maxSum = maxEnd = temp;
        } else {
            maxEnd = max(temp, maxEnd + temp);
            maxSum = max(maxEnd, maxSum);
        }
    }
    cout << maxSum << "\n";
    return 0;
}
