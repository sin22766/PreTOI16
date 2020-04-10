#include <bits/stdc++.h>

using namespace std;

int main() {
    string word;
    int len, temp, result;
    for (int t = 0; t < 5; ++t) {
        cin >> word;
        len = word.size(), result = 1;
        for (int i = 1; i < len; ++i) {
            if (word[i] == word[0]) {
                temp = 0;
                if ((len - i) % i == 0) {
                    for (int j = i; j < len; ++j) {
                        if (word[j % i] != word[j]) {
                            break;
                        }
                        temp++;
                    }
                    if (temp + i == len) {
                        result++;
                    }
                }
            }
        }
        cout << result << "\n";
    }
    return 0;
}