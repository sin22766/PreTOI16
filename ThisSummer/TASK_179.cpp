#include<bits/stdc++.h>

using namespace std;

int main() {
    int k, result = 0;
    string word;
    cin >> k >> word;
    int strL = word.length();
    queue<int> P, T;
    for (int i = 0; i < strL; ++i) {
        if (word[i] == 'P') {
            P.push(i);
        } else {
            T.push(i);
        }
    }

    while (!P.empty() && !T.empty()) {
        if (abs(P.front() - T.front()) <= k) {
            result++;
            P.pop();
            T.pop();
        } else if (T.front() < P.front()) {
            T.pop();
        } else {
            P.pop();
        }
    }
    cout << result;
    return 0;
}
