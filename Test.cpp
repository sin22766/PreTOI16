#include <bits/stdc++.h>

using namespace std;

int findflag(int n) {
    if (n < 1) return 0;
    else if (n <= 2) return 1;
    else return findflag(n - 1) + findflag(n - 2);
}

int main() {
    /*stack<char> st;
    set<char> ope = {'+', '-', '*', '/', '^'};
    string s = "*-A/BC-/AKL";
    reverse(s.begin(), s.end());

    for (auto i:s) {
        if (ope.count(i)) {
            auto a = st.top();
            st.pop();
            auto b = st.top();
            st.pop();

            auto temp = a + b + i;

            st.push(temp);
        } else {
            st.push(i);
        }
    }
    int v = st.top();
    cout << v;*/
    cout << findflag(9);
    return 0;
}