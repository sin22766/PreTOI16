#include <bits/stdc++.h>

using namespace std;

int main() {
    int T, n, previous, curr, temp;
    string input, result;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> input;
        result.clear();
        previous = 0;
        n = input.size();
        for (int i = 0; i < n; ++i) {
            curr = input[i] - '0';
            if (curr > previous) {
                for (int j = 0; j < curr - previous; ++j) {
                    result += '(';
                }
            } else if (curr < previous) {
                for (int j = 0; j < previous - curr; ++j) {
                    result += ')';
                }
            }
            result += input[i];
            previous = curr;
        }
        temp = result[result.size() - 1] - '0';
        for (int k = 0; k < temp; ++k) {
            result += ')';
        }
        cout << "Case #" << t << ": " << result << "\n";
    }
    return 0;
}