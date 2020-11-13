#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

bool fill_all(int sudoku[9][9], int &row, int &col) {
    for (row = 0; row < 9; ++row) {
        for (col = 0; col < 9; ++col) {
            if (sudoku[row][col] == 0) {
                return false;
            }
        }
    }
    return true;
}

bool isSafe(int sudoku[9][9], int row, int col, int num) {
    for (int i = 0; i < 9; ++i) {
        if (sudoku[row][i] == num || sudoku[i][col] == num) {
            return false;
        }
    }
    int start_row = (row / 3) * 3;
    int start_col = (col / 3) * 3;
    for (int i = start_row; i < start_row + 3; ++i) {
        for (int j = start_col; j < start_col + 3; ++j) {
            if (sudoku[i][j] == num) {
                return false;
            }
        }
    }
    return true;
}

bool solveSudoku(int sudoku[9][9]) {
    int row, col;
    if (fill_all(sudoku, row, col)) {
        return true;
    }
    for (int i = 1; i <= 9; ++i) {
        if (isSafe(sudoku, row, col, i)) {
            sudoku[row][col] = i;
            if (solveSudoku(sudoku)) {
                return true;
            }
            sudoku[row][col] = 0;
        }
    }
    return false;
}

int main() {
    int sudoku[9][9];
    string temp;
    for (int i = 0; i < 9; ++i) {
        cin >> temp;
        for (int j = 0; j < 9; ++j) {
            sudoku[i][j] = temp[j] - '0';
        }
    }

    if (solveSudoku(sudoku)) {
        for (auto &i : sudoku) {
            for (int j : i) {
                cout << j << " ";
            }
            cout << '\n';
        }
    } else {
        cout << "Can't Solve";
    }
    return 0;
}