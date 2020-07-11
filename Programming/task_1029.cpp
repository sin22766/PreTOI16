#include <bits/stdc++.h>

using namespace std;

void Check(set<int> &Magnet, int num) {
    if (Magnet.count(num)) {
        Magnet.erase(num);
    } else {
        Magnet.insert(num);
    }
}

int main() {
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);
    set<int> Magnet;
    for (int i = 0; i < m; ++i) {
        int a, k;
        scanf("%d %d", &a, &k);
        Check(Magnet, a);
        Check(Magnet, a + k);
    }
    Magnet.insert(1);
    Magnet.insert(n + 1);
    for (int i = 0; i < q; ++i) {
        int question;
        scanf("%d", &question);
        auto up = Magnet.upper_bound(question);
        auto low = up;
        --low;
        cout << *up - *low << "\n";
    }
    return 0;
}

