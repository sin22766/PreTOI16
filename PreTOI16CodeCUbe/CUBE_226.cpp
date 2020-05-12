#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q;
    scanf(" %d %d", &n, &q);
    int door[n + 5];
    for (int i = 1; i <= n; ++i) {
        scanf(" %d", &door[i]);
    }
    int s, e, a, b, prev, curr;
    bool dead;
    vector<bool> visited;
    for (int i = 0; i < q; ++i) {
        scanf(" %d %d %d %d", &s, &e, &a, &b);
        swap(door[a], door[b]);
        prev = -1, curr = s;
        dead = false;
        visited.assign(n + 5, false);
        while (prev != curr) {
            if (visited[curr]) {
                break;
            }
            visited[curr] = true;
            if (curr == e) {
                dead = true;
                cout << "DEAD\n";
                break;
            }
            prev = curr;
            curr = door[curr];
        }
        if (!dead) {
            cout << "SURVIVE\n";
        }
        swap(door[a], door[b]);
    }
    return 0;
}
