#include <bits/stdc++.h>

using namespace std;

double distance(pair<int, int> p1, pair<int, int> p2) {
    return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}

int main() {
    int n, m;
    cin >> n >> m;
    pair<int, int> boy[n], girl[m];
    for (int i = 0; i < n; ++i) {
        cin >> boy[i].first >> boy[i].second;
    }
    for (int i = 0; i < m; ++i) {
        cin >> girl[i].first >> girl[i].second;
    }
    double min = 1000000, temp;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            temp = distance(boy[i], girl[j]);
            if (temp < min) {
                min = temp;
            }
        }
    }
    printf("%.3lf\n", min);
    return 0;
}