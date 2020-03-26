#include <bits/stdc++.h>

using namespace std;

int main() {
    int k, p, q, m, b, p_count;
    double price, p_price;
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> Q;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        cin >> p >> q;
        Q.emplace(((double) p / (double) q), q);
    }
    cin >> m;
    for (int j = 0; j < m; ++j) {
        price = 0;
        scanf(" %d", &b);
        while (b > 0) {
            p_price = Q.top().first;
            p_count = Q.top().second;
            if (b >= p_count) {
                price += (p_price * (double) p_count);
                b -= p_count;
                Q.pop();
            } else {
                price += (double) b * Q.top().first;
                p_count -= b;
                Q.pop();
                Q.emplace(p_price, p_count);
                b = 0;
            }
        }
        printf("%.3f\n", price);
    }
    return 0;
}