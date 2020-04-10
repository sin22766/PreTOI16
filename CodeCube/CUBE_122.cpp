#include <bits/stdc++.h>

using namespace std;
char arr[501][501];
bool visited[501][501][20];

char owner[3] = {'J', 'B', 'P'}, ownerR[3] = {'j', 'b', 'p'};
int mover[4][2] = {{-1, 0},
                   {0,  1},
                   {1,  0},
                   {0,  -1}}; // N,E,S,W

int main() {
    //define
    int n, m, startI, startJ, endI = 0, endJ = 0;
    cin >> n >> m;

    //input
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> arr[i][j];
            if (arr[i][j] == 'S') {
                startI = i, startJ = j;
            } else if (arr[i][j] == 'E') {
                endI = i, endJ = j;
            }
        }
    }

    //shortest path
    queue<tuple<int, int, int, int>> q;
    q.emplace(0, startI, startJ, 0);
    while (!q.empty()) {
        int walked = get<0>(q.front());
        int posI = get<1>(q.front());
        int posJ = get<2>(q.front());
        int rel = get<3>(q.front());
        bool permission = true;
        bitset<3> relBit(rel);
        q.pop();
        if (posI == endI && posJ == endJ) {
            cout << walked;
            return 0;
        }

        if (visited[posI][posJ][rel]) {
            continue;
        }
        visited[posI][posJ][rel] = true;

        for (int i = 0; i < 3; ++i) {
            if (arr[posI][posJ] == owner[i] && !relBit[2 - i]) {
                permission = false;
                break;
            }
        }
        if (!permission) {
            continue;
        }
        for (int i = 0; i < 3; ++i) {
            if (arr[posI][posJ] == ownerR[i]) {
                relBit[2 - i] = true;
            }
        }
        for (auto i : mover) {
            if (posI + i[0] >= 0 && posI + i[0] < n && posJ + i[1] >= 0 &&
                posJ + i[1] < m && arr[posI + i[0]][posJ + i[1]] != '#') {
                q.emplace(walked + 1, posI + i[0], posJ + i[1], relBit.to_ulong());
            }
        }

    }
    cout << "-1";
    return 0;
}