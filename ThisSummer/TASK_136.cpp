#include <bits/stdc++.h>

using namespace std;

int n, m;
double land[5][5], minN = 2e18;

pair<int, int> checker[8] = {{-1, -1},
                             {-1, 0},
                             {-1, 1},
                             {0,  1},
                             {1,  1},
                             {1,  0},
                             {1,  -1},
                             {0,  -1}};

void backtrack(int row, int col, double price, int buy) {
    if (buy == m * n) {
        cout << "______________\n";
        minN = min(minN, price);
        return;
    }
    for (auto i:checker) {
        if (land[row + i.first][col + i.second] != 0) {
            double oldLand = land[row][col];
            for (auto j:checker) {
                if (land[row + j.first][col + j.second] != 0) {
                    land[row + j.first][col + j.second] += land[row][col] * 10 / 100;
                }
            }
            land[row][col] = 0;

            backtrack(row + i.first, col + i.second, price + land[row + i.first][col + i.second], buy + 1);

            land[row][col] = oldLand;
            for (auto j:checker) {
                if (land[row + j.first][col + j.second] != 0) {
                    land[row + j.first][col + j.second] -= land[row][col] * 10 / 100;
                }
            }
        }
    }
}

int main() {
    scanf(" %d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            scanf(" %lf", &land[i][j]);
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            backtrack(i, j, land[i][j], 1);
        }
    }
    printf("%.2lf", minN);
    return 0;
}
