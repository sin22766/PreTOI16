#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, x, y, r, broken,bombed = 0;
    scanf(" %d %d",&n,&m);
    vector<pair<int, int>> yun;
    vector<int> bomb;
    for (int i = 0; i < n; ++i) {
        scanf(" %d %d",&x,&y);
        yun.emplace_back(x, y);
    }
    for (int j = 0; j < m; ++j) {
        scanf(" %d %d %d",&x,&y,&r);
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