#include <bits/stdc++.h>

using namespace std;

bool backtrack(string word) {
    if(*word.end() == 'A'){
        return true;
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        string word;
        cin >> word;
        cout << "Case #" << t << ": ";
        if (word.find('.') != string::npos) {

        } else {
            cout << "N\n";
        }
    }
    return 0;
}