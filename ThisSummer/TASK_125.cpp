#include <bits/stdc++.h>

using namespace std;

int L[100010], R[100010], S[100010];
int qs[200010];
long long qsAns[200010];

int main() {
    int m, q;
    scanf("%d %d", &m, &q);
    vector<int> event(1, 0);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &L[i], &R[i], &S[i]);
        event.push_back(L[i]);
        event.push_back(R[i] + 1);
    }
    sort(event.begin(), event.end());
    event.resize(unique(event.begin(), event.end()) - event.begin());
    for (int i = 0; i < m; ++i) {
        int start = lower_bound(event.begin(), event.end(), L[i]) - event.begin();
        int end = lower_bound(event.begin(), event.end(), R[i] + 1) - event.begin();
        qs[start] += S[i];
        qs[end] -= S[i];
    }
    int size = event.size();

    for (int i = 1; i < size; ++i) {
        qs[i] += qs[i - 1];
    }

    for (int i = 1; i < size; ++i) {
        long long range = event[i] - event[i - 1] - 1;
        qsAns[i] += qsAns[i - 1] + (qs[i - 1] * range) + qs[i];
    }

    for (int i = 0; i < q; ++i) {
        int l, r;
        scanf("%d %d", &l, &r);
        int start = upper_bound(event.begin(), event.end(), l - 1) - event.begin() - 1;
        int end = upper_bound(event.begin(), event.end(), r) - event.begin() - 1;
        long long sumL = qsAns[start] + qs[start] * (l - event[start] - 1);
        long long sumR = qsAns[end] + qs[end] * (r - event[end]);
        cout << sumR - sumL << "\n";
    }

    return 0;
}
