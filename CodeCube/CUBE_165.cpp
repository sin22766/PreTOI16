#include <bits/stdc++.h>

using namespace std;

int find(int parent[], int i) {
    if (parent[i] != i) {
        return parent[i] = find(parent, parent[i]);
    }
    return i;
}

void merge(int parent[], int i, int j) {
    parent[find(parent, i)] = find(parent, j);
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    int type[n + 1];
    for (int i = 1; i <= n; ++i) {
        cin >> type[i];
    }
    return 0;
}