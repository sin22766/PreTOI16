#include <bits/stdc++.h>

using namespace std;
int cannon[10000010];

int main() {
    int n, m, k, l, rail, can, result;
    int maxN = 0, bound, start, end;
    scanf(" %d %d %d %d", &n, &m, &k, &l);
    for (int i = 0; i < n; ++i) {
        scanf(" %d", &can);
        cannon[can] = 1;
        maxN = can;
    }
    for (int i = 1; i <= maxN; ++i) {
        cannon[i] += cannon[i - 1];
    }
    for (int i = 0; i < k; ++i) {
        result = bound = 0;
        for (int j = 0; j < m; ++j) {
            scanf(" %d", &rail);
            start = max(bound, rail - l);
            end = min(maxN, rail + l);
            if (start > end) {
                continue;
            }
            result += cannon[end] - cannon[start - 1];
            bound = end + 1;
        }
        cout << result << "\n";
    }
    return 0;
}