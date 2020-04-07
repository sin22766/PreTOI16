#include <bits/stdc++.h>

using namespace std;

int getBit(int x) {
    char temp;
    cout << x << endl;
    scanf(" %c", &temp);
    if (temp == 'N') {
        exit(0);
    }
    return temp - '0';
}

int main() {
    bool check_same, check_dif;
    int T, B, curr, temp, state, com, same, dif;
    cin >> T >> B;
    for (int t = 0; t < T; ++t) {
        vector<int> result(B + 1, -1);
        vector<int> status(B / 2 + 1, 0);
        same = dif = 0;
        curr = state = 1;
        for (int i = 1; i <= 150 && curr <= B / 2; ++i) {
            if (i % 10 == 1) {
                check_same = check_dif = false;
                if (same) {
                    if (getBit(same) != result[same]) {
                        check_same = true;
                    }
                    i++;
                }
                if (dif) {
                    if (getBit(dif) != result[dif]) {
                        check_dif = true;
                    }
                    i++;
                }
                if (check_dif || check_same) {
                    for (int j = 1; j <= B / 2; ++j) {
                        if ((status[j] == 1 && check_same) || (status[j] == 2 && check_dif)) {
                            result[j] = 1 - result[j];
                            result[B - j + 1] = 1 - result[B - j + 1];
                        }
                    }
                    if (!state) {
                        state = 1;
                    }
                }
            }
            if (state) {
                com = curr;
            } else {
                com = B - curr + 1;
            }
            result[com] = getBit(com);

            if (!state) {
                if (result[curr] != result[com]) {
                    dif = curr;
                    status[curr] = 2;
                } else {
                    same = curr;
                    status[curr] = 1;
                }
            }
            state = 2 - state;
        }
        for (int k = 1; k <= B; ++k) {
            cout << result[k];
        }
        cout << endl;
        scanf(" %c", &temp);
        if (temp == 'N') {
            exit(0);
        }
    }
    return 0;
}