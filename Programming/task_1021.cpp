#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    long long price;
    char mode;
    cin >> n;
    priority_queue<int> q;
    for (int i = 0; i < n; ++i){
        scanf(" %c",&mode);
        if (mode == 'P') {
            scanf(" %lld",&price);
            q.push(price);
        } else if (mode == 'Q') {
            if (q.empty()) {
                cout << "-1\n";
            } else {
                cout << q.top() << "\n";
                q.pop();
            }
        }
    }
    return 0;
}
