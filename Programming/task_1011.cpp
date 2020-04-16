#include <bits/stdc++.h>

using namespace std;

pair<int, int> mover[2] = {{1, 0},
                           {0, 1}};//NEW

int score = 0, row, col;
char game[8][8];

void gravity(int &r, int &c, int &d) {
    c += d;
    while (game[r + 1][c] == '-') {
        swap(game[r + 1][c], game[r][c]);
        r++;
    }
}

void gravityBelow(int r, int &c) {
    while (r > 0 && game[r - 1][c] != '-' && game[r - 1][c] != '#') {
        swap(game[r - 1][c], game[r][c]);
        r--;
    }
}

void bfs(int r, int c) {
    vector<pair<int, int>> gravity_help;
    char curr = game[r][c];
    //Reset Visited

    queue<pair<int, int>> q;

    q.emplace(r, c);

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        score += 5;
        game[x][y] = '-';
        gravity_help.emplace_back(x, y);

        for (auto i:mover) {
            if (x + i.first < row && y + i.second < col && game[x + i.first][y + i.second] == curr) {
                q.emplace(x + i.first, y + i.second);
            }
        }
    }
    for (auto i:gravity_help) {
        gravityBelow(i.first, i.second);
    }
}

int main() {
    int com, dir, r, c;
    bool change;
    char d;
    cin >> row >> col;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cin >> game[i][j];
        }
    }
    cin >> com;
    for (int i = 0; i < com; ++i) {
        cin >> r >> c >> d;
        dir = (d == 'L') ? -1 : 1;
        if (r >= 0 && c >= 0 && r < row && c < col && game[r][c] != '#' && game[r][c] != '-') {
            if (game[r][c + dir] == '-') {
                swap(game[r][c + dir], game[r][c]);
                gravityBelow(r, c);
                gravity(r, c, dir);
                change = true;
                while (change) {
                    change = false;
                    for (int j = 0; j < row; ++j) {
                        for (int k = 0; k < col; ++k) {
                            if (game[j][k] != '-' && game[j][k] != '#') {
                                if (game[j][k] == game[j][k + 1] || game[j][k] == game[j + 1][k]) {
                                    change = true;
                                    bfs(j, k);
                                }
                            }
                        }
                    }
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