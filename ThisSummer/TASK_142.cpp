#include <bits/stdc++.h>

using namespace std;
//Using Backtracking
int board[10][10];

bool isSafe(int row, int col, int want) {
    for (int i = 0; i < 9; ++i) {
        if (board[row][i] == want || board[i][col] == want) {
            return false;
        }
    }
    for (int j = 0; j < 3; ++j) {
        for (int i = 0; i < 3; ++i) {
            if (board[j + (row - row % 3)][i + (col - col % 3)] == want) {
                return false;
            }
        }
    }
    return true;
}

bool unFill(int &row, int &col) {
    for (row = 0; row < 9; ++row) {
        for (col = 0; col < 9; ++col) {
            if (board[row][col] == 0) {
                return true;
            }
        }
    }
    return false;
}

bool Solver() {
    int row, col;
    if (!unFill(row, col)) {
        return true;
    }
    for (int j = 1; j <= 9; ++j) {
        if (isSafe(row, col, j)) {
            board[row][col] = j;
            if (Solver()) {
                return true;
            }
            board[row][col] = 0;
        }
    }
    return false;
}

int main() {
    freopen("sudoku.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    string boardName, temp;
    for (int k = 0; k < 100; ++k) {
        cin >> boardName >> temp;
        boardName += " " + temp;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                cin >> board[i][j];
            }
        }
        Solver();
        cout << boardName << "\n";
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
