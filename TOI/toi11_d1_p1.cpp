#include <bits/stdc++.h>

using namespace std;

int operate(int i, int j) {
    if (i - j == 1 || i + j == 0) {
        return 2;
    } else if (i - j == -2) {
        return 0;
    } else {
        return 1;
    }
}

bool backtrack(string num) {
    if (num.size() == 2) {
        return num.front() == '0' && num.back() == '2';
    } else {
        for (int i = 0; i < num.size() - 1; ++i) {
            char first = num[i], second = num[i + 1];
            num[i + 1] = operate(first - '0', second - '0') + '0';
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