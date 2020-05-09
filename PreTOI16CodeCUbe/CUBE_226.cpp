#include <bits/stdc++.h>

using namespace std;

int find(int parent[], int i) {
    if (i != parent[i]) {
        return parent[i] = find(parent, parent[i]);
    }
    return i;
}

void merge(int parent[], int i, int j) {
    parent[find(parent, i)] = find(parent, j);
}

int main() {
    int n, q;
    scanf(" %d %d", &n, &q);
    int door[n], parent[n];
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
    }
    for (int i = 0; i < n; ++i) {
        scanf(" %d", &door[i]);
        merge(parent, i, door[i] - 1);
    }
    int s, e, a, b;
    for (int i = 0; i < q; ++i) {
        scanf(" %d %d %d %d", &s, &e, &a, &b);
        swap(parent[a - 1], parent[b - 1]);
        if (parent[s - 1] == parent[e - 1]) {
            cout << "DEAD\n";
        } else {
            cout << "SURVIVE\n";
        }
        swap(parent[a - 1], parent[b - 1]);
    }
    return 0;
}
