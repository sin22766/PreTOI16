#include <bits/stdc++.h>

using namespace std;

int main() {
    string a, b, result;
    cin >> a >> b;
    if (b.size() > a.size()) {
        result = a;
        a = b;
        b = result;
    }
    result.clear();
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int aL = a.size(), bL = b.size(), temp = 0;
    for (int i = 0; i < aL; ++i) {
        if (i >= bL) {
            if (a[i] + temp > '9') {
                result.push_back(a[i] + temp - 10);
                temp = 1;
            } else {
                result.push_back(a[i] + temp);
                temp = 0;
            }
            continue;
        }
        if (a[i] + b[i] - 96 + temp < 10) {
            result.push_back(a[i] + b[i] - 48 + temp);
            temp = 0;
        } else {
            result.push_back(a[i] + b[i] - 48 + temp - 10);
            temp = 1;
        }
    }
    reverse(result.begin(), result.end());
    cout << result;
    return 0;
}
