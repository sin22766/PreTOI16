#include <bits/stdc++.h>

using namespace std;
using lli = long long int;

const lli hash_num = 1e9 + 7;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    char word[n + 5];
    scanf("%s", word);

    lli l = 1, r = n;
    lli maxLength = 0;

    while (l <= r) {
        lli mid = (l + r) / 2;
        lli maxDup = 0;
        map<lli, lli> count;

        //Finding first Hash
        lli curr_hash = 0;
        lli base = 1;

        for (int i = 0; i < mid; ++i) {
            curr_hash *= hash_num;
            curr_hash += word[i] - 'a';
            if (i != 0) {
                base *= hash_num;
            }
        }

        count[curr_hash] = 1;

        for (int i = mid; i < n; ++i) {
            curr_hash -= (word[i - mid] - 'a') * base;
            curr_hash *= hash_num;
            curr_hash += (word[i] - 'a');

            count[curr_hash] += 1;
            maxDup = max(maxDup, count[curr_hash]);
            if (maxDup >= m) {
                break;
            }
        }

        if (maxDup >= m) {
            maxLength = max(maxLength, mid);
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << maxLength;
    return 0;
}
