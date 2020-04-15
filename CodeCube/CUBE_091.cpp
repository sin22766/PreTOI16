#include <bits/stdc++.h>

using namespace std;

int minN = 1e7, gray = 2e6, n;
string result;
bool check = false;

void backtrack(char game[], int curr) {
    if (curr > n) {
        check = true;
        if (gray < minN) {
            minN = gray;
            result = game;
        }
    } else if (game[curr] != 'X') {
        backtrack(game, curr + 1);
    } else {
        if (game[curr + 1] + game[curr - 1] == 'B' + 'W') {
            gray++;
            game[curr] = 'G';
            backtrack(game, curr + 1);
            game[curr] = 'X';
            gray--;
        }
        if (game[curr + 1] != 'B' && game[curr - 1] != 'B') {
            game[curr] = 'B';
            backtrack(game, curr + 1);
            game[curr] = 'X';
        }
        if (game[curr + 1] != 'W' && game[curr - 1] != 'W') {
            game[curr] = 'W';
            backtrack(game, curr + 1);
            game[curr] = 'X';
        }
    }
}

int main() {
    //input
    cin >> n;
    char game[n + 5];
    for (int i = 1; i <= n; ++i) {
        cin >> game[i];
    }
    game[0] = game[n + 1] = 'X';

    backtrack(game, 1);
    if (check) {
        for (int i = 1; i <= n; ++i) {
            cout << result[i];
        }
    } else {
        cout << "No Answer\n";
    }
    return 0;
}

