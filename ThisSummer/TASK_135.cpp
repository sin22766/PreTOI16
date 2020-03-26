#include <bits/stdc++.h>

using namespace std;
//Using Backtracking

int roundA = 0;
double sum_price, min_price = 10000000, sum_priceA = 0, sum_priceB = 0;

void choosing(int const price_a[], int const price_b[], int &n, int item_a, int item_b) {
    if (item_a + item_b == n) {
        sum_price = sum_priceA - (sum_priceA * item_a / 100.0) + sum_priceB - (sum_priceB * item_b / 100.0);
        if (sum_price < min_price) {
            min_price = sum_price;
        }
        return;
    }
    roundA++;
    sum_priceA += price_a[item_a + item_b];
    choosing(price_a, price_b, n, item_a + 1, item_b);
    sum_priceA -= price_a[item_a + item_b];
    sum_priceB += price_b[item_a + item_b];
    choosing(price_a, price_b, n, item_a, item_b + 1);
    sum_priceB -= price_b[item_a + item_b];
}

int main() {
    int n;
    cin >> n;
    int shop_a[n], shop_b[n];
    for (int i = 0; i < 2 * n; ++i) {
        (i < n) ? cin >> shop_a[i] : cin >> shop_b[i % n];
    }
    choosing(shop_a, shop_b, n, 0, 0);
    printf("%.2lf", min_price);
    return 0;
}
