#include <bits/stdc++.h>

using namespace std;

int maxN = 0, dist, x = 0, y = 0;

map<char, pair<int, int>> mode = {{'N', {0,  1}},
                                  {'E', {1,  0}},
                                  {'S', {0,  -1}},
                                  {'W', {-1, 0}}};

void checkDist(const string &command) {
    for (auto i:command) {
        x += mode[i].first;
        y += mode[i].second;
    }
}

void signalDis(string &command, int &n, int curr) {
    if (command.size() == n) {
        maxN = 0;
        return;
    }
    if (curr == n) {
        dist = abs(x) + abs(y);
        if (dist > maxN) {
            maxN = dist;
        }
        return;
    }
    for (auto &i:command) {
        x -= mode[i].first;
        y -= mode[i].second;
        signalDis(command, n, curr + 1);
        x += mode[i].first;
        y += mode[i].second;
    }
}

int main() {
    string command;
    int n;
    cin >> command >> n;
    checkDist(command);
    signalDis(command, n, 0);
    cout << maxN*2;
    return 0;
}
