#include <bits/stdc++.h>

using namespace std;
//Using Backtracking
int maxScore = -2e9, score = 0;
vector<pair<int, int>> maxRook, rook;
int board[20][20];
bool isSafe[20];

void Chooser(int &n, int row) {
    if (row == n) {
        if (score > maxScore) {
            maxScore = score;
            maxRook = rook;
        }
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (!isSafe[i]) {
            isSafe[i] = true;
            int temp = board[row][i];
            score += temp;
            board[row][i] = 1001;
            rook.emplace_back(row + 1,i + 1);
            Chooser(n, row + 1);
            isSafe[i] = false;
            board[row][i] = temp;
            score -= temp;
            rook.pop_back();
        }
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> board[i][j];
        }
    }
    Chooser(n, 0);
    cout << maxScore << "\n";
    for (auto i:maxRook) {
        cout << i.first << " " << i.second << "\n";
    }
    return 0;
}
