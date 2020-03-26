#include <bits/stdc++.h>

using namespace std;

string to_roman(int n){
    string roman;
    int num[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
    string rom[] = {"i", "iv", "v", "ix", "x", "xl", "l", "xc", "c", "cd", "d", "cm", "m"};
    int i = 12;
    while (n > 0) {
        int dig = n / num[i];
        n = n % num[i];
        while (dig--) {
            roman += rom[i];
        }
        --i;
    }
    return roman;
}

int main() {
    int n;
    cin >> n;
    string roman;
    for (int i = 1; i <= n; ++i) {
        roman+=to_roman(i);
    }
    int iN, v, x, l, c;
    iN = v = x = l = c = 0;
    for (char j:roman) {
        switch(j){
            case 'i':
                iN++;
                break;
            case 'v':
                v++;
                break;
            case 'x':
                x++;
                break;
            case 'l':
                l++;
                break;
            case 'c':
                c++;
                break;
            default:
                break;
        }
    }
    cout << iN << " " << v << " " << x << " " << l << " " << c << "\n";
    return 0;
}
