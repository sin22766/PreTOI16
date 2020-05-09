#include <bits/stdc++.h>

using namespace std;

default_random_engine generator;
uniform_int_distribution<int> distribution(1, 200000);
uniform_int_distribution<int> distribution2(1, 100000);

int main() {

    cout << 200000 << " " << 100 << " " << 200000 << "\n";
    for (int i = 0; i < 200000; ++i) {
        cout << distribution(generator) << " ";
    }
    cout << "\n";
    int a;
    for (int i = 0; i < 200000; ++i) {
        a = distribution2(generator);
        cout << a << " " << a + distribution2(generator) << "\n";
    }
    return 0;
}

