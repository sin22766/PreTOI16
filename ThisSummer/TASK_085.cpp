#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, temp;
    cin >> n;
    map<int, int> num;
    for (int i = 1; i <= n; ++i) {
        scanf(" %d", &temp);
        if (!num[temp]) {
            num[temp] = i;
        }
    }

    cin >> m;
    for (int i = 0; i < m; ++i) {
        scanf(" %d", &temp);
        if (num[temp]) {
            cout << num[temp] << "\n";
        } else {
            cout << "Not found\n";
        }
    }
    return 0;
}