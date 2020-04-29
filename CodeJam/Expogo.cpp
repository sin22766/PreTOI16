#include <bits/stdc++.h>

using namespace std;

int tar_x;
int tar_y;
string word;
set<pair<int, int>> visited;

bool solver(int x, int y, int i, string &curr_word) {
    if (i > 100) {
        return false;
    } else if (x == tar_x && y == tar_y) {
        if (word.empty() || curr_word.size() < word.size()) {
            word = curr_word;
        }
        return true;
    } else {
        curr_word.push_back('N');
        solver(x, y + pow(2, i - 1), i + 1, curr_word);
        curr_word.pop_back();
        curr_word.push_back('E');
        solver(x + +pow(2, i - 1), y, i + 1, curr_word);
        curr_word.pop_back();
        curr_word.push_back('S');
        solver(x, y - pow(2, i - 1), i + 1, curr_word);
        curr_word.pop_back();
        curr_word.push_back('W');
        solver(x - pow(2, i - 1), y, i + 1, curr_word);
        curr_word.pop_back();
    }
}

int main() {
    int T, x, y;
    string curr;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        curr.clear();
        word.clear();
        cin >> tar_x >> tar_y;
        solver(0, 0, 1, curr);
        cout << "Case #" << t << ": " << word << "\n";
    }

    return 0;
}