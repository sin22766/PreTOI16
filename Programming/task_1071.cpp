#include <bits/stdc++.h>

using namespace std;
int mapG[2000][2000];

int main() {
    int n, m, x, y, r, broken;
    scanf(" %d %d",&n,&m);
    for (int i = 0; i < n; ++i) {
        scanf(" %d %d",&x,&y);
        mapG[y][x] = 1;
    }
    for (int i = 0; i < m; ++i) {
        scanf(" %d %d %d",&x,&y,&r);
        broken = 0;
        for (int j = y - r; j <= y + r; ++j) {
            for (int k = x - r; k <= x + r; ++k) {
                if (j >= 0 && j <= 1010 && k >= 0 && k <= 1010){
                    if (mapG[j][k] == 1) {
                        broken++;
                        mapG[j][k] = 0;
                    }
                }
            }
        }
        cout << broken << "\n";
    }
    return 0;
}