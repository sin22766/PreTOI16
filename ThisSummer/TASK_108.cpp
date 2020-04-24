#include <bits/stdc++.h>

using namespace std;

int main() {
    pair<int, int> checker[3];
    string first, second;
    cin >> first >> second;
    int f_size = first.size(), s_size = second.size(), maxN = 0, curr = 0;
    int dp[f_size][s_size];
    for (int i = 0; i < f_size; ++i) {
        for (int j = 0; j < s_size; ++j) {
            if (!i || !j) {
                dp[i][j] = first[i] == second[j];
            } else {
                if (first[i] == second[j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = 0;
                }
            }
            if (dp[i][j] > maxN) {
                maxN = dp[i][j];
                curr = i;
            }
        }
    }
    cout << first.substr(curr - maxN + 1, maxN);
    return 0;
}
