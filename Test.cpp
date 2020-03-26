#include <bits/stdc++.h>

using namespace std;
int game[10000][10000];

int main() {
    int n, m, x, y, r, broken,bombed = 0;
    cin >> n >> m;
    vector<int> bomb;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        yun.emplace_back(x, y);
    }
    for (int j = 0; j < m; ++j) {
        cin >> x >> y >> r;
        broken = 0;
        bomb.clear();
        if(bombed>=n){
            cout << 0;
            continue;
        }
        for (int k = 0; k < yun.size();) {
            if (yun[k].first >= x - r && yun[k].first <= x + r && yun[k].second >= y - r && yun[k].second <= y + r) {
                yun.erase(yun.begin()+k);
                broken++;
            }else{
                k++;
            }
        }
        cout << broken << "\n";
    }
    return 0;
}