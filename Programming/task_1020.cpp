#include <bits/stdc++.h>
using namespace std;

int main() {
    string word,r_word;
    cin >> word;
    r_word = word;
    reverse(r_word.begin(),r_word.end());
    for (int i = 0; i < word.size(); ++i) {
        word[i] = (char)toupper(word[i]);
        r_word[i] = (char)toupper(r_word[i]);
    }
    if(word==r_word){
        word = word.substr(0,word.size()/2);
        r_word = word;
        reverse(r_word.begin(),r_word.end());
        if(word==r_word){
            cout << "Double Palindrome";
        }else{
            cout << "Palindrome";
        }
    }else{
        cout << "No";
    }
    return 0;
}
