#include <bits/stdc++.h>

#define powerTwo 1073741824
using namespace std;

const int modulor = 1e9 + 7;

int allCombination(int n) {
    long long sum = 1, count, temp;
    count = n / 30;
    for (int i = 0; i < count; ++i) {
        sum = ((powerTwo % modulor) * (sum % modulor)) % modulor;
    }
    count = n % 30;
    temp = pow(2, count);
    sum = ((temp % modulor) * (sum % modulor)) % modulor;
    return (int) sum;
}

int main() {
    int n, m;
    scanf(" %d %d", &n, &m);
    int t, a, b, parent[n + 5];
    for (int i = 0; i <= n; ++i) {
        parent[i] = i;
    }

    return 0;
}

