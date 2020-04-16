#include <bits/stdc++.h>

using namespace std;

void gravity() {

}

int main() {
    int row, col, com, score = 0, mover, r, c;
    char dir;
    cin >> row >> col;
    char game[row + 1][col + 1];
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cin >> game[i][j];
        }
    }
    cin >> com;
    for (int i = 0; i < com; ++i) {
        cin >> r >> c >> dir;
        mover = (dir == 'L') ? -1 : 1;
        if (game[r][c] != '#' && game[r][c] != '-') {
            if (game[r][c + mover] == '-') {
                game[r][c + mover] = game[r][c];
                game[r][c] = '-';
                c += mover;
                while (game[r + 1][c] == '-') {
                    game[r + 1][c] = game[r][c];
                    game[r][c] = '-';
                    r++;
                }
                int x = 1, y = 1, temp;
                bool horizontal = false;
                while (game[r][c + x] == game[r][c] || game[r][c - y] == game[r][c]) {
                    if (game[r][c + x] == game[r][c]) {
                        game[r][c + x] = '-';
                        temp = 0;
                        while (r - temp > 0 && game[r - temp - 1][c + x] != '#' && game[r - temp - 1][c + x] != '-' &&
                               game[r - temp][c + x] == '-') {
                            swap(game[r - temp][c + x], game[r - temp - 1][c + x]);
                            temp++;
                        }
                        x++;
                        score += 5;
                    }
                    if (game[r][c - y] == game[r][c]) {
                        game[r][c - y] = '-';
                        temp = 0;
                        while (r - temp > 0 && game[r - temp - 1][c - y] != '#' && game[r - temp - 1][c - y] != '-' &&
                               game[r - temp][c - y] == '-') {
                            game[r - temp][c - y] = game[r - temp - 1][c - y];
                            game[r - temp - 1][c - y] = '-';
                            temp++;
                        }
                        y++;
                        score += 5;
                    }
                    horizontal = true;
                }
                bool vertical = false;
                while (game[r + 1][c] == game[r][c]) {
                    game[r][c] = '-';
                    r++;
                    vertical = true;
                    score += 5;
                }
                if (vertical || horizontal) {
                    game[r][c] = '-';
                    score += 5;
                }
            } else {
                score -= 5;
            }
        } else {
            score -= 5;
        }
    }
    cout << score << "\n";
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cout << game[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;

}
