#include <bits/stdc++.h>

using namespace std;

int part_sum(int const arr[], int first, int last) {
    int sum = 0;
    for (int i = first; i < last; ++i) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    int price[n];
    for (int i = 0; i < n; ++i) {
        cin >> price[i];
    }
    int minP = 10000000, a, b, c, second, third;
    for (int i = 1; i < n - 2; ++i) {
        for (int j = i + 1; j < n - 1; ++j) {
            a = part_sum(price, 0, i);
            b = part_sum(price, i, j);
            c = part_sum(price, j, n);
            int maxBoy = max(max(a, b), c), minBoy = min(min(a, b), c);
            if (maxBoy - minBoy < minP) {
                minP = maxBoy - minBoy;
                second = i, third = j;
            }
        }
    }
    cout << second+1 << " " << third+1;
    return 0;
}