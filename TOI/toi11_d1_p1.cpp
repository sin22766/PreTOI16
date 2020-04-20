#include <bits/stdc++.h>

using namespace std;

char sega[3][3] = {{'2', '1', '0'},
                   {'2', '1', '1'},
                   {'1', '2', '1'}};

map<string, int> dp1;
map<string, int> dp2;

bool backtrack(string num) {
    if (num.size() == 2) {
        return num.front() == '0' && num.back() == '2';
    } else {
        for (int i = 0; i < num.size() - 1; ++i) {
            if (dp1[num.substr(0, i)]) {

            }
            if (dp2[num.substr(i, num.size() - i)]) {

            }
            char first = num[i], second = num[i + 1];
            num[i + 1] = sega[first - '0'][second - '0'];
            num.erase(num.begin() + i);
            if (backtrack(num)) {
                return true;
            }
            num.insert(num.begin() + i, first);
            num[i + 1] = second;
        }
    }
    return false;
}

int main() {
    int n;
    string s;
    for (int i = 0; i < 20; ++i) {
        cin >> n >> s;
        if (backtrack(s)) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }
    return 0;
}