#include <bits/stdc++.h>

using namespace std;

map<char, array<int, 2>> moveP = {{'N', {-1, 0}},
                                  {'E', {0,  1}},
                                  {'S', {1,  0}},
                                  {'W', {0,  -1}}};// use (y,x)
int score[4] = {1, 1, 1, 1};

bool checkPossible(int *pos, int moveX, int moveY, int n) {
    return pos[0] + moveY >= 0 && pos[0] + moveY < n && pos[1] + moveX >= 0 && pos[1] + moveX < n;
}

int main() {
    int n, m;
    char dir;
    cin >> n >> m;
    int game[n][n], curr_pos[4][2] = {{0,     n - 1},
                                      {n - 1, n - 1},
                                      {n - 1, 0},
                                      {0,     0}};// use (y,x)
    for (auto i:game) {
        fill_n(i, n, 0);
    }
    for (int k = 0; k < 4; ++k) {
        game[curr_pos[k][0]][curr_pos[k][1]] = (k + 1) * 10;
    }
    string lap[m];
    for (int i1 = 0; i1 < 4; ++i1) {
        for (int i = 0; i < m; ++i) {
            cin >> dir;
            lap[i].push_back(dir);
        }
    }
    for (int j = 0; j < m; ++j) {
        for (int k = 0; k < 4; ++k) {
            dir = lap[j][k];
            int move_x, move_y;
            auto pos = curr_pos[k % 4];
            move_x = moveP[dir][1], move_y = moveP[dir][0];
            if (checkPossible(pos, move_x, move_y, n) && game[pos[0] + move_y][pos[1] + move_x] < 10) {
                if (game[pos[0] + move_y][pos[1] + move_x] != 0) {
                    score[game[pos[0] + move_y][pos[1] + move_x] - 1]--;
                }
                score[k % 4]++;
                game[pos[0] + move_y][pos[1] + move_x] = game[pos[0]][pos[1]];
                game[pos[0]][pos[1]] = game[pos[0]][pos[1]] / 10;
                pos[0] += move_y;
                pos[1] += move_x;
            }
        }
    }
    vector<int> winner;
    int maxN = 0, sumScore = 0;
    for (int l = 1; l <= 4; ++l) {
        sumScore += score[l - 1];
        if (score[l - 1] > maxN) {
            winner.clear();
            maxN = score[l - 1];
            winner.push_back(l);
        } else if (score[l - 1] == maxN) {
            winner.push_back(l);
        }
    }
    if (sumScore < n * n) {
        cout << "No" << "\n";
    } else {
        cout << winner.size() << " " << maxN << "\n";
        sort(winner.begin(), winner.end());
        for (auto i:winner) {
            cout << i << "\n";
        }
    }
    return 0;
}