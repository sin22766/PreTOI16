#include <bits/stdc++.h>

using namespace std;

int sega[3][3] = {{2, 1, 0},
                  {2, 1, 1},
                  {1, 2, 1}};

int bruceForce(string word, int n) {
    int temp = word.size();
    if (temp == 2) {
        return sega[word[0] - '0'][word[1] - '0'];
    }
}

int main() {
    int n, temp;
    string s;
    for (int i = 0; i < 20; ++i) {
        cin >> n >> s;
        temp = s.size();
        for (int j = 0; j < temp; ++j) {

        }
    }
    return 0;
}