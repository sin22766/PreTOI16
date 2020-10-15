#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, orchid;
    scanf("%d", &n);
    vector<int> temp;
    temp.push_back(-1e9);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &orchid);
        int k = upper_bound(temp.begin(), temp.end(), orchid) - temp.begin();
        if (k >= temp.size()) {
            temp.push_back(orchid);
        } else {
            temp[k] = orchid;
        }
    }
    cout << n - temp.size() + 1;
    return 0;
}
