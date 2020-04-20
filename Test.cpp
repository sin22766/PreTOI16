#include <bits/stdc++.h>

using namespace std;

int main() {
    string s = "123456";
    s.erase(s.begin() + 1);
    s.insert(s.begin() + 1, '2');
    cout << s[2] << '\n';
    cout << s;
    return 0;
}