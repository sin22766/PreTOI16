#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int n;
int numpad[4][3] = {{1,  2, 3},
                    {4,  5, 6},
                    {7,  8, 9},
                    {-1, 0, -1}};
pair<int, int> checker[5] = {{0,  0},
                             {-1, 0},
                             {0,  -1},
                             {1,  0},
                             {0,  1}};

long long dp_temp[4][3][20];


long long dp(int row, int col, int t) {
    if (t >= n) {
        return 1;
    } else if (dp_temp[row][col][t]) {
        return dp_temp[row][col][t];
    }
    for (auto i:checker) {
        int next_row = row + i.first;
        int next_col = col + i.second;
        bool isNotX = numpad[next_row][next_col] != -1;
        if (next_col >= 0 && next_col <= 2 && next_row >= 0 && next_row <= 3 && isNotX) {
            dp_temp[row][col][t] += dp(next_row, next_col, t + 1);
        }
    }
    return dp_temp[row][col][t];
}

int main() {
    scanf("%d", &n);
    long long sum_way = 0;
    for (int i = 0; i <= 3; ++i) {
        for (int j = 0; j <= 2; ++j) {
            if (numpad[i][j] != -1) {
                sum_way += dp(i, j, 1);
            }
        }
    }
    cout << sum_way;
    return 0;
}
