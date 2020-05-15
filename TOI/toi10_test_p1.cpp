#include <bits/stdc++.h>

using namespace std;
bool prime[10000000];

int main() {
    int n;
    scanf(" %d", &n);
    vector<int> primeN;
    for (int i = 2; i * i < 1e7; ++i) {
        if (!prime[i]) {
            for (int j = i * i; j < 1e7; j += i) {
                prime[j] = true;
            }
        }
    }
    for (int i = 2; i < 1e7; ++i) {
        if (!prime[i]) {
            primeN.push_back(i);
        }
    }
    cout << primeN[n - 1];
    return 0;
}