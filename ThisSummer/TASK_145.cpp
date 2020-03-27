#include <bits/stdc++.h>

using namespace std;

int findParent(int parent[], int person) {
    if (parent[person] != person) {
        return parent[person] = findParent(parent, parent[person]);
    } else {
        return person;
    }
}

void mergeFriend(int parent[], int person1, int person2) {
    parent[findParent(parent, person1)] = findParent(parent, person2);
}

int main() {
    int n, m, q;
    cin >> n >> m;
    int u, v, parent[n];
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
    }
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        mergeFriend(parent, u - 1, v - 1);
    }
    cin >> q;
    for (int i = 0; i < q; ++i) {
        cin >> u >> v;
        (findParent(parent, u - 1) == findParent(parent, v - 1)) ? cout << "Yes\n" : cout << "No\n";
    }
    return 0;
}
