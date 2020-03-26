#include <bits/stdc++.h>

using namespace std;

int main() {
    string command;
    int n;
    cin >> command >> n;
    if (command.size() == n) {
        cout << '0';
        return 0;
    }
    map<char, int> count = {{'N', 0},
                            {'E', 0},
                            {'S', 0},
                            {'W', 0}};
    for (char i : command) {
        count[i]++;
    }
    int x, y;
    for (int j = n; j > 0; --j) {
        x = count['E'] - count['W'];
        y = count['N'] - count['S'];
        if ((y < 0 && count['N'] != 0)) {
            count['N']--;
        } else if (y >= 0 && count['S'] != 0) {
            count['S']--;
        } else if (x < 0 && count['E'] != 0) {
            count['E']--;
        } else if (x >= 0 && count['W'] != 0) {
            count['W']--;
        } else if (y < 0) {
            count['S']--;
        } else if (y > 0) {
            count['N']--;
        } else if (x < 0) {
            count['W']--;
        } else if (x > 0) {
            count['E']--;
        }
    }
    x = count['E'] - count['W'];
    y = count['N'] - count['S'];
    cout << (abs(x) + abs(y)) * 2;
    return 0;
}
