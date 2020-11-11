#include <bits/stdc++.h>

using namespace std;
using tiii = tuple<int, int, int>;
int dp_table[305][1005];

int dp(vector<tiii> graph[], int current, int end, int time) {
    if (time <= 0 && current != end) {
        return -1e9;
    } else if (dp_table[current][time]) {
        return dp_table[current][time];
    }
    for (auto i:graph[current]) {
        int v = get<0>(i);
        int c = get<1>(i);
        int w = get<2>(i);

        if (time - w >= 0) {
            dp_table[current][time] = max(dp(graph, v, end, time - w), dp_table[current][time]);
        }
    }
    return dp_table[current][time];
}

int main() {
    int n, m, k, s, t;
    scanf("%d%d%d%d%d", &n, &m, &k, &s, &t);
    vector<tiii> graph[n + 5];
    for (int i = 0; i < m; ++i) {
        int a, b, c, w;
        scanf("%d%d%d%d", &a, &b, &c, &w);
        graph[a].emplace_back(b, c, w);
        graph[b].emplace_back(a, c, w);
    }

    cout << dp(graph, s, t, k);
    return 0;
}