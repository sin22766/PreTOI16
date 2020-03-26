#include <bits/stdc++.h>

using namespace std;

int checker[8][2] = {{-1, 0},
                     {-1, 1},
                     {0,  1},
                     {1,  1},
                     {1,  0},
                     {1,  -1},
                     {0,  -1},
                     {-1, -1}};
//using (y,x) from N clockwise to NW

bool checkMark(char check, char curr) {
    return check != curr && check != '.';
}

bool checkPossible(int &curr_row, int &curr_col, int &next_row, int &next_col) {
    return curr_col + next_col < 8 && curr_col + next_col >= 0 && curr_row + next_row < 8 && curr_row + next_row >= 0;
}

void gameUpdate(string game[8], int lastRow, int lastCol, char curr) {
    for (auto &i : checker) {
        if (checkPossible(lastRow, lastCol, i[0], i[1])) {
            if (checkMark(game[lastRow + i[0]][lastCol + i[1]], curr)) {
                int y = lastRow + i[0], x = lastCol + i[1];
                vector<char *> updater;
                while (y >= 0 && y < 8 && x >= 0 && x < 8) {
                    if (game[y][x] != curr) {
                        updater.push_back(&game[y][x]);
                        y += i[0];
                        x += i[1];
                    } else {
                        if (curr == 'X') {
                            for (auto j:updater) {
                                *j = 'X';
                            }
                        } else if (curr == 'O') {
                            for (auto j:updater) {
                                *j = 'O';
                            }
                        }
                        break;
                    }
                }
            }
        }
    }
}

int main() {
    string dG[] = {"........", "........", "........", "...OX...", "...XO...", "........", "........", "........"};
    int k, row;
    char col, curr;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        cin >> col >> row;
        if (i % 2 == 0) {
            curr = 'X';
            dG[row - 1][col - 'a'] = 'X';
        } else {
            curr = 'O';
            dG[row - 1][col - 'a'] = 'O';
        }
        gameUpdate(dG, row - 1, col - 'a', curr);
    }
    for (auto i:dG) {
        for (int j = 0; j < 8; ++j) {
            cout << i[j];
        }
        cout << "\n";
    }
    return 0;
}
