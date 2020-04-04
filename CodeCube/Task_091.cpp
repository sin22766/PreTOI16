#include <bits/stdc++.h>

using namespace std;


bool backtrack(char game[], int n, int curr) {
    if (curr > n) {
        return true;
    }
    if (game[curr] == 'X') {
        for (auto i:"BW") {
            if (game[curr + 1] + game[curr - 1] == 'B' + 'W') {
                game[curr] = 'G';
            } else if (game[curr + 1] != 'B' && game[curr - 1] != 'B') {
                game[curr] = 'B';
            } else if (game[curr + 1] != 'W' && game[curr - 1] != 'W') {
                game[curr] = 'W';
            } else {
                game[curr] = i;
            }

            if (backtrack(game, n, curr + 1)) {
                return true;
            }

            game[curr] = 'X';
        }
    } else {
        if (backtrack(game, n, curr + 1)) {
            return true;
        }
    }
    return false;
}

int main() {
    int n;

    //input
    cin >> n;
    char game[n + 5];
    for (int i = 1; i <= n; ++i) {
        cin >> game[i];
    }

    //process
    if (backtrack(game, n, 1)) {
        for (int i = 1; i <= n; ++i) {
            cout << game[i];
        }
    } else {
        cout << "No Answer\n";
    }
    return 0;
}

