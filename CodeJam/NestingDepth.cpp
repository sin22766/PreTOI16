#include <bits/stdc++.h>

using namespace std;

void Solver(string &word) {
    int n = word.size();
    for (int i = 0; i < n; ++i) {
        if (word[i] != '0' && word[i] != '(') {
            word.insert(i, 1, 'w');
        }
    }
}

int main() {
    int T;
    string input;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> input;

        cout << "Case #" << t << ": " << input << "\n";
    }
    return 0;
}