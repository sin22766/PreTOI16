#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<string> result;
    string word;
    cin >> word;
    int w_len = word.length(), dp[w_len][w_len], maxN = 1, j;
    for (int s_length = 2; s_length <= w_len; ++s_length) {
        for (int i = 0; i <= w_len - s_length + 1; ++i) {
            j = i + s_length - 1;
            if (word[i] == word[j] && j - i == 1) {
                dp[i][j] = 2;
            } else if (word[i] == word[j]) {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            } else {
                dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
            }
        }
    }
    sort(result.begin(), result.end());
    for (string &i:result) {
        cout << i << "\n";
    }
    return 0;
}