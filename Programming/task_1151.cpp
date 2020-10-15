#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,tree;
    scanf("%d", &n);
    vector<int> temp;
    temp.push_back(-1e9);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &tree);
        int k = lower_bound(temp.begin(), temp.end(), tree) - temp.begin() - 1;
        if (k >= temp.size() - 1) {
            temp.push_back(tree);
        } else {
            temp[k + 1] = tree;
        }
    }
    cout << temp.size() - 1;
    return 0;
}
