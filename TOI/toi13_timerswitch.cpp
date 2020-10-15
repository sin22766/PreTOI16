#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    string word;
    scanf("%d", &n);
    cin >> word;
    string temp = word + word;

    vector<int> d;
    for (int i = 1; i <= n; ++i) {
        if (n % i == 0) {
            d.push_back(i);
        }
    }

    for (int i:d) {
        if (temp.substr(i, n) == word) {
            cout << i;
            break;
        }
    }
    return 0;
}
